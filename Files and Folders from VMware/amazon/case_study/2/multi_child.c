#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
	int i,j,k,r,fd1,fd2,pos;
	char ch;
	i=fork();
	if(i==0)
	{
		sleep(5);
		printf("First Child Process Id: %d\n",getpid());
		printf("Parent Process Id: %d\n",getppid());
		fd1=open("data.txt",O_RDONLY);
		fd2=open("new_data.txt",O_WRONLY|O_CREAT,0666);
		pos=lseek(fd1,0,SEEK_SET);
		while(pos<=1000)
		{
			r=read(fd1,&ch,1);
			printf("%c",ch);
			write(fd2,&ch,1);
			if(r!=0||ch==' '||ch=='\n')
				pos++;
		}
		printf("\nCurrent Cursor position: %d\n",pos);
		close(fd1);
		close(fd2);
		
	}
	else
	{
		j=fork();
		if(j==0)
		{
			sleep(10);
			printf("Second Child Process Id: %d\n",getpid());
			printf("Parent Process Id: %d\n",getppid());
			fd1=open("data.txt",O_RDONLY);
			fd2=open("new_data.txt",O_WRONLY|O_CREAT|O_APPEND,0666);
			pos=lseek(fd1,1001,SEEK_SET);
			while(pos<=2000)
			{
				r=read(fd1,&ch,1);
				printf("%c",ch);
				write(fd2,&ch,1);
				if(r!=0||ch==' '||ch=='\n')
					pos++;
			}
			printf("\nCurrent Cursor position: %d\n",pos);
			close(fd1);
			close(fd2);
		}
		else
		{
			k=fork();
			if(k==0)
			{
				sleep(15);
				printf("Third Child Process Id: %d\n",getpid());
				printf("Parent Process Id: %d\n",getppid());
				fd1=open("data.txt",O_RDONLY);
				fd2=open("new_data.txt",O_WRONLY|O_CREAT|O_APPEND,0666);
				lseek(fd1,2001,SEEK_SET);
				while(1)
				{
					r=read(fd1,&ch,1);
					printf("%c",ch);
					write(fd2,&ch,1);
					if(r==0)
						break;
				}
				close(fd1);
				close(fd2);
			}
			else
			{
				printf("\n");
				wait(0);
				wait(0);
				wait(0);
				//while(1); - use this one for infinite loop and then check in another shell using pstree but disable wait() before
			}
		}
	
	}
}

