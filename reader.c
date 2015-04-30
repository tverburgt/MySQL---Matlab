#include <stdio.h>
#include <my_global.h>
#include <mysql.h>


void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}


int main(int argc, char **argv)
{  
  
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

  if (mysql_query(con, "SELECT * FROM mixer_temp")) 
  {
      finish_with_error(con);
  }
  
  MYSQL_RES *result = mysql_store_result(con); // getting the result set
  
  if (result == NULL) 
  {
      finish_with_error(con);
  }


  int num_fields = mysql_num_fields(result);  // We get number of fields (columns) in the table
  MYSQL_ROW row;
  int i=0;
  FILE *fp=fopen("hello.csv","w");
  
 
 
  
  while ((row = mysql_fetch_row(result))) 
  { 
      for(i = 0; i < num_fields; i++) 
      { 
          
        if(i==0 )
        {
       
        printf("%s %c", row[i] ? row[i] : "NULL",',');
        fprintf(fp,"%s %c", row[i] ? row[i] : "NULL",',');
        }
        
        else if (i==1)
        {
        printf(" %s", row[i] ? row[i] : "NULL");
        fprintf(fp," %s", row[i] ? row[i] : "NULL");
    }
      
      } 
          fprintf(fp,"\n");
          printf("\n"); 
  }
  
  
  fclose(fp);
  mysql_free_result(result);
  mysql_close(con);
  
  exit(0);
} 
  