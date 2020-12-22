#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
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
	if(str1==NULL || str2==NULL)
	{
		perror("Too few Arguements");
	}
	else if(strcmp(str1,"-v")!=0 && strcmp(str1,"-p")!=0)
	{
		perror("Invalid Command");
	}
	else if(str3==NULL && str2!=NULL && strcmp(str1,"-v")==0)
	{
		int a=mkdir(str2,0700);
		if(a!=-1)
		{
			printf("Directory Successfully Created\n");
		}
		else
		{
			perror("Cannot Create Directory\n");
		}
	}
	else if(str3!=NULL && str2!=NULL && strcmp(str1,"-v")==0)
	{
		int a=mkdir(str2,0700);
		int b=mkdir(str3,0700);
		if(a!=-1)
		{
			printf("Directory1 Successfully Created\n");	
		}
		if(b!=1)
		{
			printf("Directory2 Succesfully Created\n");
		}
		else
		{
			printf("Directory Created");
		}
		
	}
	else if(str3==NULL && str2!=NULL && strcmp(str1,"-p")==0)
	{
		char *po=strtok(str2,",\n");
		while(po!=NULL)
		{
			int a=mkdir(po,0700);
			if(a==-1)
			{
				perror("Cannot Create Directory");
				break;
			}
			chdir(po);
			po=strtok(NULL,",\n");
		}
	}

	exit(0);
}
