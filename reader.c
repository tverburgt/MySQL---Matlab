//Code of Tyrone Verburgt, Ion Comendant & Assyzhan Mussin

#include <stdio.h>
#include <my_global.h>
#include <mysql.h>

//Fuction that is called with an error occurs. An error
//message is printed out and the connection with the database 
//is closed.
void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}


int main(int argc, char **argv)
{  
  //Fetch a vector pointer of type MYSQL
  MYSQL *con = mysql_init(NULL);

  //If not able to fetch vector pointer...throw an error message.
  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }
  //Connect database on the localhost with a root username
  //and password.
  if (mysql_real_connect(con, "localhost", "root", "root", 
          "process_control", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con); 
  }  

  //Make a querry to database to connect with table mixer_temp.
  //If returns true, throw error message and close connection
  //with database.
  if (mysql_query(con, "SELECT * FROM mixer_temp")) 
  {
      finish_with_error(con);
  }
  
  MYSQL_RES *result = mysql_store_result(con); // getting the result set
  
  //If result set equal NULL, throw errow message and close
  //connection with database.
  if (result == NULL) 
  {
      finish_with_error(con);
  }

  // We get number of fields (columns) in the table. This would be 2 columns
  int num_fields = mysql_num_fields(result);  

  MYSQL_ROW row;
  int i=0;
  //A .csv file called plot is created. If it already exists...overwrite.
  FILE *fp=fopen("plot.csv","w");
  
 
 
  
  while ((row = mysql_fetch_row(result))) 
  { 
      for(i = 0; i < num_fields; i++) 
      { 
          
        if(i==0 )
        {
        //Timestamp is printed to the shell
        printf("%s %c", row[i] ? row[i] : "NULL", ',');
        //Timestamp is written to plot.csv
        fprintf(fp,"%s %c", row[i] ? row[i] : "NULL", ',');
        //Note: A comma is appended after each timestamp because
        //a comma represents a new column in a csv file. This 
        //allows the data value to be plotted in Octave.
        }
        
        else if (i==1)
        {
        //temperature is printed to the shell.
        printf(" %s", row[i] ? row[i] : "NULL");
        //temperature is appended along side  timestamp.
        fprintf(fp," %s", row[i] ? row[i] : "NULL");

    }
      
      }   //Carriage return is inserted to create a new line.
      	  //A new line represents a new row in the .csv file.
          fprintf(fp,"\n"); 
          printf("\n"); 
  }
  
  
  fclose(fp);  //Close .csv fiel
  mysql_free_result(result);
  mysql_close(con); //Close connection to database.
  
  exit(0);
} 
  