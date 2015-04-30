/*#include <stdio>

int main()
{
	FILE fp;
	int i;
	fp = fopen("hello.csv","w");
	
	if (fp)
	{
		for(i=0;i<10;i++)
		{
			fprintf(fp,"%d,%d\n", i, 5*i);
		{
	}
}

*/

#include <my_global.h>
#include <mysql.h>
#include <stdio.h>

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
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  
  if (mysql_real_connect(con, "127.0.0.1", "root", "root", 
          "process_control", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
  if (mysql_query(con, "SELECT * FROM mixer_temp")) 
  {
      finish_with_error(con);
  }
  
  //This structure represents the result of a query that 
  //returns rows (SELECT, SHOW, DESCRIBE, EXPLAIN).
  MYSQL_RES *result = mysql_store_result(con);
  

  //If result equals NULL, throw error message.
  if (result == NULL) 
  {
      finish_with_error(con);
  }

  //This give the number of row within result.
  int num_fields = mysql_num_fields(result);



  //This is a type-safe representation of one row of data. It 
  //is currently implemented as an array of counted byte 
  //strings. Rows are obtained using mysql_fetch_row().
  MYSQL_ROW row;  //Number of fields (columns).
  


  FILE *fp = fopen("hello.csv","w");
  int i;
  

  if(fp)
  {
  	while ((row = mysql_fetch_row(result))) 
  		{ 
      		for(i = 0; i < num_fields; i++) 
      		{ 
      			//fprintf(fp,"%d,%d\n", i, 5*i);
      			//fprintf(fp, "%s\n", row[i]);
          		fprintf(fp,"%s", row[i] ? row[i] : "NULL");
          		//if(!(i%2 == 0) )
          		//fprintf(fp,"\n");

          			
      		} 
          fprintf(fp, "\n"); 
  		}
  }
 
  fclose(fp);
  
  mysql_free_result(result);
  mysql_close(con);
  
  exit(0);
}

