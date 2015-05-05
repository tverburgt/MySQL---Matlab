/* strchr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "2015-04-29 14:02:45";
  char * pch;
  printf ("Looking for the 's' character in \"%s\"...\n",str);
  pch=strchr(str,'s');
  char _time[] = "";


	int i = 0;
	int z = 0;
	int y;
	for(i ; i <= strlen(str); i++)
	{
		printf("%s\n", "In 1st loop");
		if(str[i] == ' ')
		{
			i++;
			for(i; i <= strlen(str); i++)
			{
				printf("%s\n", "In loop");
				printf("The length of string: %d\n", strlen(str));
				printf("The value of i is: %d\n", i);
				_time[z] = str[i];
				z++;
			}
		} 
		
	}

  printf("The value of the new string: %s\n", _time);
  return 0;
}
