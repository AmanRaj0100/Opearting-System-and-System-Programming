#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd1,fd2,k;
	char rdata[50],wdata[50];
	fd1=open("f1",O_WRONLY);
	fd2=open("f2",O_RDONLY);
	k=fork();
	if(k==0)
	{
		while(1)
		{
			read(fd2,rdata,50);
			printf("%s\n",rdata);
		}
	}
	else
	{
		while(1)
		{
			scanf("%s",wdata);
			write(fd1,wdata,strlen(wdata)+1);
		}

	}
	close(fd1);
	close(fd2);
}
