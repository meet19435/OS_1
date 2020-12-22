#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void main()
{	printf("Enter the Arguements/Options:");
	char c[40];
	FILE *ft;
	char *name="/home/meetmodi1/Desktop/Assignment1_Ques2/History.txt";
	ft=fopen(name,"a+");
	if(ft==NULL)
	{
		perror("Error\n");
		exit(1);
	}
	fgets(c,40,stdin);
	fputs(c,ft);
	fclose(ft);
	char *str1;
	char *str2;
	char *str3;
	char *p=strtok(c," \n");
	if(p!=NULL)
	{
		str1=p;
	}
	else
	{
		str1=NULL;
	}
	
	p=strtok(NULL," \n");
	if(p!=NULL)
	{
		str2=p;
	}
	else
	{
		str2=NULL;
	}
	p=strtok(NULL," \n");
	if(p!=NULL)
	{
		str3=p;

	}
	else
	{
		str3=NULL;
	}
	if(str2!=NULL || str3!=NULL)
	{
		perror("Too many Arguements");
	}
	if(str1==NULL)
	{
		struct tm *pd;
		time_t curt=time(NULL);
		pd=localtime(&curt);
		printf("%s\n",asctime(pd));
	}
	else if(str1!=NULL && strcmp(str1,"--help")==0)
	{
		FILE *df;
		df=fopen("/home/meetmodi1/Desktop/Assignment1_Ques2/date.txt","r");
		if(df==NULL)
		{
			perror("File Not Found");
			exit(0);
		}
		char dline[300];
		while(fgets(dline,300,df))
		{
			printf("%s",dline);

		}
		fclose(df);
	}
	else
	{
		perror("Invalid Command");
	}
	exit(0);
}
