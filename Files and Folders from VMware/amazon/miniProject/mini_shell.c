#include<stdio.h> //standard input/output library functions
#include<fcntl.h> //manipulates file descriptor
#include<unistd.h> //standard symbolic constant and types
#include<string.h> //manipulates array of characters
#include<stdlib.h> //defines four variable types, several macros, and various functions for performing general functions

void myCatfn(char fname[])
{
	int fd;
	fd=open(fname,O_RDONLY);
	if(fd == -1)
		printf("%s: No such file exists\n",fname);
	else
	{
		char ch;
		int k;
		while(1)
		{
			k=read(fd,&ch,1);
			if(k == 0)
				break;
			else
				printf("%c",ch);
		}
		printf("\n");
		close(fd);
	}
}

void myHeadfn(char fname[])
{
	int fd,cnt=1;
	char ch;
	fd=open(fname,O_RDONLY);
	if(fd == -1)
		printf("%s: No such file exists\n",fname);
	else
	{
		while(1)
		{
			if(cnt<=10)
			{
				read(fd,&ch,1);
				printf("%c",ch);
				if(ch=='\n')
					cnt++;
			}
			else
				break;	
		}
	printf("\n");
	close(fd);
	}
}

void myTailfn(char fname[])
{
	int k,fd,cnt=0;
	char ch;
	fd=open(fname,O_RDONLY);
	if(fd == -1)
		printf("%s: No such file exists\n",fname);
	else
	{
		lseek(fd,0,SEEK_END);
		while(cnt<10)
		{
			lseek(fd,-2,SEEK_CUR);
			read(fd,&ch,1);
			if(ch == '\n')
				cnt++;
		}
		while(1)
		{
			k=read(fd,&ch,1);
			printf("%c",ch);
			if(k == 0)
				break;
		}
	printf("\n");
	close(fd);
	}
}

void myCpfn(char fname[], char dname[])
{
	char ch;
	int k,fd1,fd2;
	fd1=open(fname,O_RDONLY);

	if(fd1==-1)
	{
		printf("Source file not available, Cannot copy\n");
		exit(0);
	}
	else
	{
		fd2=open(dname,O_WRONLY|O_CREAT,0666);
		while(1)
		{
			k=read(fd1,&ch,1);
			if(k==0)
				break;
			else
				write(fd2,&ch,1);
		}
		close(fd1);
		close(fd2);
		
	}
}

void myMvfn(char fname[], char dname[])
{
	char ch;
	int k,fd1,fd2;
	fd1=open(fname,O_RDONLY);

	if(fd1==-1)
	{
		printf("Source file not available, Cannot move/rename\n");
		exit(0);
	}
	else
	{
		fd2=open(dname,O_WRONLY|O_CREAT,0666);
		while(1)
		{
			k=read(fd1,&ch,1);
			if(k==0)
				break;
			else
				write(fd2,&ch,1);
		}
		close(fd1);
		close(fd2);
		unlink(fname);
	}
}

void myRmfn(char fname[])
{
	int k,fd;
	fd=open(fname,O_RDONLY);	

	if(fd == -1)
	{
		printf("No such file exists, Cannot delete\n");
		exit(0);
	}
	else
	{
		unlink(fname);
	}
}

void showfn(char fname[])
{
	int k,fd,cnt=0;
	char ch;
	fd=open(fname,O_RDONLY);
	if(fd == -1)
		printf("%s: No such file exists\n",fname);
	else
	{
		lseek(fd,0,SEEK_END);
		while(cnt<50)
		{
			lseek(fd,-2,SEEK_CUR);
			read(fd,&ch,1);
			if(ch == '\n')
				cnt++;
		}
		while(1)
		{
			k=read(fd,&ch,1);
			printf("%c",ch);
			if(k == 0)
				break;
		}
	printf("\n");
	close(fd);
	}
}

void history(int i,char cmd[], char fname[])
{
	write(i,cmd,strlen(cmd));
	write(i," ",1);
	write(i,fname,strlen(fname));
	write(i," ",1);
}


int main()
{	
	int i;
	char cmd[20],fname[20];  //Variables for the command and the filename	
	
	system("clear");	//Clears the shell screen
	
	while(1)
	{
		printf("code@Mini_Shell$ ");

		scanf("%s",cmd);
		scanf("%s",fname);
		
		i=open("history",O_WRONLY|O_CREAT|O_APPEND,0666);
		
		if(strcmp(cmd,"mycat") == 0)
		{
			history(i,cmd,fname);
			write(i,"\n",1);
			myCatfn(fname);
		
		}
		else if(strcmp(cmd,"myhead") == 0)
		{
			history(i,cmd,fname);
			write(i,"\n",1);
			myHeadfn(fname);
		
		}
		else if(strcmp(cmd,"mytail") == 0)
		{
			history(i,cmd,fname);
			write(i,"\n",1);
			myTailfn(fname);
		
		}
		else if(strcmp(cmd,"mycp") == 0)
		{
			char dname[20];
			scanf("%s",dname);
			history(i,cmd,fname);
			write(i,dname,strlen(dname));
			write(i,"\n",1);
			myCpfn(fname,dname);
		
		}
		else if(strcmp(cmd,"mymv") == 0)
		{
			char dname[20];
			scanf("%s",dname);
			history(i,cmd,fname);
			write(i,dname,strlen(dname));
			write(i,"\n",1);
			myMvfn(fname,dname);
		
		}
		else if(strcmp(cmd,"myrm") == 0)
		{
			history(i,cmd,fname);
			write(i,"\n",1);
			myRmfn(fname);
		
		}
		else if(strcmp(cmd,"show") == 0)
		{
			history(i,cmd,fname);
			write(i,"\n",1);
			showfn(fname);
		}
		else if((strcmp(cmd,"exit") == 0) && (strcmp(fname,"shell") == 0))
		{
			history(i,cmd,fname);
			write(i,"\n",1);
			break;
		}
		else
		{
			printf("Command \'%s\' not found\n",cmd);
		}
	}
	close(i);
}
