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
	
	if(str2==NULL || str1==NULL)
	{
		perror("Enter the File Name/Too few Arguements");
	}
	else if(strcmp(str1,"-f")!=0 && strcmp(str1,"-i")!=0)
	{
		perror("Invalid Command");
	}
	else if(str3==NULL && str2!=NULL)
	{
			if(strcmp(str1,"-f")==0)
			{
				remove(str2);
			}
			else if(strcmp(str1,"-i")==0)
			{
				char con[2];
				printf("Y to delete/N to Ignore\n");
				fgets(con,2,stdin);
				if(strcmp(con,"Y")==0)
				{
					int a=remove(str2);
					if(a==-1)
					{
						perror("No Such File Found\n");
					}
					else if(a==0)
					{
						printf("File Successfully Deleted\n");
					}
				}
				else if(strcmp(con,"N")==0)
				{
					printf("File Not Deleted");
				}
				else
				{
					perror("Invalid Option Selected");
				}

			}
	}
	else if(str3!=NULL)
	{
		if(strcmp(str1,"-f")==0)
			{
				remove(str2);
				remove(str3);
			}
		else if(strcmp(str1,"-i")==0)
		{
			char con[2];
			int con1;
			printf("Y to delete/N to Ignore File1:");
			fgets(con,2,stdin);
			if(strcmp(con,"Y")==0)
			{
				int a=remove(str2);
				if(a==-1)
				{
					perror("No Such File Found\n");
				}
				else if(a==0)
				{
					printf("File Successfully Deleted\n");
				}
			}
			else if(strcmp(con,"N")==0)
			{
				printf("File Not Deleted\n");
			}
			else
			{
				perror("Invalid Option Selected");
			}
			printf("1 to delete/0 to Ignore File2:");
			scanf("%d",&con1);
			if(con1==1)
			{
				int a=remove(str3);
				if(a==-1)
				{
					perror("No Such File Found\n");
				}
				else if(a==0)
				{
					printf("File Successfully Deleted\n");
				}
			}
			else if(con1==0)
			{
				printf("File Not Deleted\n");
			}
			else
			{
				perror("Invalid Option Selected");
			}

		}	
	}

	exit(0);
}
