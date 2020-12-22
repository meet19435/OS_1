#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	printf("Enter the Options/Arguements:");
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
	if(str1==NULL)
	{
		perror("Too few Arguements");
	}
	else if(str3!=NULL)
	{
		perror("Too many Arguements");
	}
	else if(str2==NULL)
	{
		perror("No File Entered");
	}
	else
	{
		FILE *ft2;
		ft2=fopen(str2,"r");
		if(ft2==NULL)
		{
			perror("File Not Found");
			exit(0);
		}
		char cline[40];
		if(strcmp(str1,"-n")==0)
		{	int count=1;
			while(fgets(cline,40,ft2))
			{
				printf("%d %s",count,cline);
				count=count+1;
			}
		}
		else if(strcmp(str1,"-E")==0)
		{
			while(fgets(cline,40,ft2))
			{	char *pt=strtok(cline,"\n");
				printf("%s$\n",pt);
				
			}
		}
		else
		{
			perror("Invalid Command");
		}

	}
	exit(0);


}
