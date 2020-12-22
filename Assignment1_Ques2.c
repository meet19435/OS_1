#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	printf("++++++++++++++Welcome to Cmd+++++++++++++++++\n");
	while(1)

	{	char ct[100];
		printf("%s:",getcwd(ct,100));
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
		char *str4;
		char *p=strtok(c," \n");
		if(p!=NULL)
		{
			str1=p;	
		}
		else
		{
			str1=NULL;
		}
		if(str1==NULL)
		{
			perror("Please Enter the Command");
			continue;
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
		p=strtok(NULL," \n");
		if(p!=NULL)
		{
			str4=p;
		}
		else
		{
			str4=NULL;
		}
		
		if(strcmp(str1,"cd")==0)
		{
			if(str2==NULL)
			{
				printf("");
			}
			else if(str4!=NULL)
			{
				perror("Too Many Arguements\n");
			}
			else
			{
				if(strcmp(str2,"-P")==0)
				{
					if(str3==NULL)
					{
						perror("Too Few Arguements");
					}
					else
					{
					int test=chdir(str3);
					if(test==0)
					{
						printf("");
					}
					else
					{
						perror("Directory not Found\n");
					}
					}
				}
				else if(strcmp(str2,"--help")==0)
				{
					FILE *cf;
					cf=fopen("/home/meetmodi1/Desktop/Assignment1_Ques2/cd.txt","r");
					if(cf==NULL)
					{
						perror("File Not Found");
					}
					char baline[300];
					while(fgets(baline,300,cf))
					{
						printf("%s",baline);
					}
					fclose(cf);
				}
				else
				{
					if(str3!=NULL)
					{
						perror("Too Many Arguements");
					}
					else
					{
						int bla=chdir(str2);
						if(bla==-1)
						{
							perror("Cannot Find Directory/Invalid Command");
						}

					}
				}
			}
		}
		else if(strcmp(str1,"pwd")==0)
		{	char c12[100];
			if(str2==NULL)
			{
				printf("%s\n",getcwd(c12,100));
			}
			else if(str3!=NULL)
			{
				perror("Too Many Arguments\n");
			}
			else if(strcmp(str2,"-P")==0)
			{
				printf("%s\n",getcwd(c12,100));
			}
			else if(strcmp(str2,"--help")==0)
			{
				FILE *pf;
				pf=fopen("/home/meetmodi1/Desktop/Assignment1_Ques2/pwd.txt","r");
				if(pf==NULL)
				{
					perror("File Not Found");
				}
				char pline[300];
				while(fgets(pline,300,pf))
				{
					printf("%s",pline);
				}
				fclose(pf);
			}	
			else
			{
				perror("Invalid Command\n");
			}
		}
		else if(strcmp(str1,"history")==0)
		{
			
			if(str3!=NULL)
			{
				printf("Too Many Arguements\n");
			}
			else if(str2!=NULL && strcmp(str2,"-c")==0)
			{
				
				FILE *ft2=fopen(name,"w");
				fprintf(ft2,"");

			}
			else if(str2!=NULL && strcmp(str2,"--help")==0)
			{
				FILE *hf;
				hf=fopen("/home/meetmodi1/Desktop/Assignment1_Ques2/history_help.txt","r");
				if(hf==NULL)
				{
					perror("File Not Found");
				}
				char hline[300];
				while(fgets(hline,300,hf))
				{
					printf("%s",hline);
				}
				fclose(hf);
			}
			else if(str2==NULL)
			{
				FILE *ft2=fopen(name,"r");
				char cline[40];
				int count=1;
				while(fgets(cline,40,ft2))
				{
					printf("%d: ",count);
					printf("%s",cline);
					count=count+1;
				}
				fclose(ft2);
			}
			else
			{
				perror("Invalid Command");
			}

		}
		else if(strcmp(str1,"echo")==0)
		{
			if(str4!=NULL || str3!=NULL)
			{
				perror("Too Many Arguements");
			}
			else if(str2==NULL)
			{
				perror("Too few Arguements");
			}
			else if(strcmp(str2,"-E")!=0 && strcmp(str2,"-n")!=0)
			{
				perror("Invalid Command");
			}
			else
			{	//printf("Entered\n");
				FILE *bla=fopen(name,"a+");
				char cin[40];
				fgets(cin,40,stdin);
				fputs(cin,bla);
				fclose(bla);
				char *cin1=cin;
				char *p2=strtok(cin1,"\n");
				cin1=p2;
				if(strcmp(str2,"-E")==0)
				{
					printf("%s\n",cin1);
				}
				else if(strcmp(str2,"-n")==0)
				{
					printf("%s",cin1);
				}
			}
		
		}
		else if(strcmp(str1,"exit")==0)
		{
			if(str3!=NULL)
			{
				perror("Too Many Arguements");
			}
			else if(str2==NULL)
			{
				exit(0);
			}
			else if(strcmp(str2,"1")==0 || strcmp(str2,"0")==0)
			{
				if(strcmp(str2,"1")==0)
				{
					exit(1);
				}
				else if(strcmp(str2,"0")==0)
				{
					exit(0);
				}	
			}
		
			else if(strcmp(str2,"--help")==0)
			{
				FILE *et;
				et=fopen("/home/meetmodi1/Desktop/Assignment1_Ques2/exit.txt","r");
				char eline[150];
				if(et==NULL)
				{
					perror("File Not Found");
					exit(0);
				}
				while(fgets(eline,150,et))
				{
					printf("%s",eline);
				}
				fclose(et);
			}
			else
			{
				perror("Invalid Option");
			}
			
		}
		else if(strcmp(str1,"cat")==0)
		{
			if(str2!=NULL)
			{
				perror("Enter the Arguments/Option in subsequentline");
			}
			char *testarg[]={"sh","-c","gcc -o /home/meetmodi1/Desktop/Assignment1_Ques2/cat.o /home/meetmodi1/Desktop/Assignment1_Ques2/cat.c; /home/meetmodi1/Desktop/Assignment1_Ques2/cat.o",0};
			if(fork()==0)
			{	
				execvp(testarg[0],testarg);
			}
			else
			{
				wait(NULL);
				
			}
		}
		else if(strcmp(str1,"date")==0)
		{
			
			if(str2!=NULL)
			{
				perror("Enter the Arguments/Option in subsequentline");
			}
			char *testarg[]={"sh","-c","gcc -o /home/meetmodi1/Desktop/Assignment1_Ques2/date.o /home/meetmodi1/Desktop/Assignment1_Ques2/date.c; /home/meetmodi1/Desktop/Assignment1_Ques2/date.o",0};
			if(fork()==0)
			{	
				execvp(testarg[0],testarg);
			}
			else
			{
				wait(NULL);
				
			}
		}
		else if(strcmp(str1,"ls")==0)
		{
			if(str2!=NULL)
			{
				perror("Enter the Arguments/Option in subsequentline");
			}
			char *testarg[]={"sh","-c","gcc -o /home/meetmodi1/Desktop/Assignment1_Ques2/ls.o /home/meetmodi1/Desktop/Assignment1_Ques2/ls.c; /home/meetmodi1/Desktop/Assignment1_Ques2/ls.o",0};
			if(fork()==0)
			{	
				execvp(testarg[0],testarg);
			}
			else
			{
				wait(NULL);
				
			}
		}
		else if(strcmp(str1,"rm")==0)
		{
			if(str2!=NULL)
			{
				perror("Enter the Arguments/Option in subsequentline");
			}
			char *testarg[]={"sh","-c","gcc -o /home/meetmodi1/Desktop/Assignment1_Ques2/rm.o /home/meetmodi1/Desktop/Assignment1_Ques2/rm.c; /home/meetmodi1/Desktop/Assignment1_Ques2/rm.o",0};
			if(fork()==0)
			{	
				execvp(testarg[0],testarg);
			}
			else
			{
				wait(NULL);
				
			}
		}
		else if(strcmp(str1,"mkdir")==0)
		{
			if(str2!=NULL)
			{
				perror("Enter the Arguments/Option in subsequentline");
			}
			char *testarg[]={"sh","-c","gcc -o /home/meetmodi1/Desktop/Assignment1_Ques2/mkdir.o /home/meetmodi1/Desktop/Assignment1_Ques2/mkdir.c; /home/meetmodi1/Desktop/Assignment1_Ques2/mkdir.o",0};
			if(fork()==0)
			{	
				execvp(testarg[0],testarg);
			}
			else
			{
				wait(NULL);
				
			}	
		}
		else
		{
			perror("Command Not Found");
		}
		str1=NULL;
		str2=NULL;
		str3=NULL;
		str4=NULL;
	}
}
