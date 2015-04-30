#include <stdio.h>
#include <my_global.h>
#include <mysql.h>

int main()
{
  FILE  *fp = fopen("hello.csv","w");
  int i;

  if (fp)
  {
    for(i=0;i<10;i++)
      fprintf(fp,"%d,%d\n", i, 5*i);
  }
  //fclose(fp);
}




/*
#include <stdio.h>
#include <my_global.h>
#include <mysql.h>

int main()
{
  FILE *f = fopen("file.txt", "w");
if (f == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}


const char *text = "Write this to the file";
fprintf(f, "Some text: %s\n", text);


int i = 1;
float py = 3.1415927;
fprintf(f, "Integer: %d, float: %f\n", i, py);


char c = 'A';
fprintf(f, "A character: %c\n", c);

fclose(f);
}
*/