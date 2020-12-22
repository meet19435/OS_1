#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
void main()
{	printf("Enter the Options/Arguements:");
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
	if(str3!=NULL)
	{
		perror("Too many Arguements");
	}
	else if(str1==NULL)
	{
		perror("Too few Arguements");
	}
	else if(strcmp(str1,"-d")==0)
	{
	
		if(str2==NULL)
		{
			printf(".\n");

		}
		else
		{
			int test=0;
			DIR *ma;
			struct dirent *fr;
			ma=opendir(".");
			if(ma)
			{
				for(fr=readdir(ma);fr!=NULL;fr=readdir(ma))
				{
					char *n=fr->d_name;
					if(strcmp(str2,n)==0)
					{	
						printf("%s\n",n);
						test=1;
						break;
					}
				}
			}
			if(test==0)
			{
				perror("Directory Not Found");
			}
		}
	}
	else if(strcmp(str1,"-a")==0)
	{
		if(str2!=NULL)
		{
			perror("Too Many Arguements");
		}
		else
		{
		DIR *main_directory;
		struct dirent *file_read;
		main_directory=opendir(".");
		if(main_directory)
		{	int count=0;
			for(file_read=readdir(main_directory);file_read!=NULL;file_read=readdir(main_directory))
			{
				char *c=file_read->d_name;
				if(count==3)
				{
					printf("%s\n",c);
					
					count=0;
					continue;	
				}
				else
				{
					printf("%s\t",c);
					count=count+1;
				}
					
				
				
			}
		} 	closedir(main_directory);
		}
	}
	else
	{
		perror("Invalid Command");
	}
	exit(0);
}
