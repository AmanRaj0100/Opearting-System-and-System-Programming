#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	char ch;
	int k,fd1,fd2;
	if(argc!=3)
	{
		printf("not enough argument passed, copy noy possible\n");
		exit(0);
	}
	fd1=open(argv[1],O_RDONLY);
	if(fd1==-1)
	{
		printf("Source file not found, copy not possible\n");
		exit(0);
	}
	else
	{
		fd2=open(argv[2],O_WRONLY|O_CREAT,0666);
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
