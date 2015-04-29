#include <stdio>

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

