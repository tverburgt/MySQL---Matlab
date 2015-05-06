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
  sprintf(SQLString,"INSERT INTO mixer_temp VALUES (to_seconds(NOW()),%f)",temperature);
  if(mysql_query(con,SQLString))
  {
    printf("%s\n",mysql_error(con));
  }
}
//to_seconds() is a mysql function that converts the current time and returns the seconds


int main(int argc, char **argv)
{  
  
  int i=0;
  MYSQL *con = mysql_init(NULL);      //mysql_init() function initializes a MYSQL object
                                      //suitable for mysql_real_connect() function

  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "root",  
          "process_control", 0, NULL, 0) == NULL)   // establishing connection to mysql database process_controll
  {
      finish_with_error(con); 
  }  

  if (mysql_query(con, "DROP TABLE IF EXISTS mixer_temp")) // Test if table exists and drop it if it does
  {
      finish_with_error(con); 
  }

  if (mysql_query(con, "CREATE TABLE mixer_temp(timestamp BIGINT, temperature FLOAT)")) // Create table with two fields
  {     
      finish_with_error(con);
  }

  for (i=0;i<100;i++)
  {
    put_temperature(con,sin(2.0*3.141592 * (double)i/100.0));
  	sleep(1);     //small delay to get different time reading
  }
  mysql_close(con);
  exit(0);
  
}