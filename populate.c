#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include <time.h>

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
int main()
{
	int i;
	MYSQL *con=mysql_init(NULL);
	if (con==NULL)
	{
		fprintf(stderr,"%s\n",mysql_error(con));
		exit(1);
		
	}
	if (mysql_real_connect(con,"127.0.0.1","root","","process_control",0,NULL,0)==NULL)
	{
		fprintf(stderr,"%s\n",mysql_error(con));
		exit(2);
	}
	for (i=0;i<100;i++)
	{
		put_temperature(con,sin(2.0*3.141592 * (double)i/100.0));
		//Hello
	}
	mysql_close(con);
	exit(0);
}
