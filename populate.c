#include <stdio.h>
#include <my_global.h>
#include <mysql.h>



void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

void put_temperature(MYSQL * con,double temperature)
{
  char SQLString[100];
  sprintf(SQLString,"INSERT INTO mixer_temp VALUES (NOW(),%f)",temperature);
  printf("%s\n",SQLString);
  if(mysql_query(con,SQLString))
  {
    printf("%s\n",mysql_error(con));
  }
}



int main(int argc, char **argv)
{  
  
  int i=0;
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "root", 
          "process_control", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con); 
  }  

  if (mysql_query(con, "DROP TABLE IF EXISTS mixer_temp")) // Test if table exists and drop it if it does
  {
      finish_with_error(con); 
  }

  if (mysql_query(con, "CREATE TABLE mixer_temp(timestamp DATETIME, temperature FLOAT)")) 
  {     
      finish_with_error(con);
  }

  for (i=0;i<100;i++)
  {
    put_temperature(con,sin(2.0*3.141592 * (double)i/100.0));
  	sleep(1);
  }
  mysql_close(con);
  exit(0);
  
}