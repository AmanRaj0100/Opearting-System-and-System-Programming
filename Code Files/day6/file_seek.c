#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd,k;
	char ch;
	fd=open(argv[1],O_RDONLY);
	while(1)
	{
		k=read(fd,&ch,1);
		if(k==0)
			break;
		else
			printf("%c",ch);
	}
	lseek(fd,0,SEEK_SET);	
	while(1)
	{
		k=read(fd,&ch,1);
		if(k==0)
			break;
		else
			printf("%c",ch);
	}

	close(fd);
}
