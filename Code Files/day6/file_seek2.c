#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd,k,pos;
	char ch;
	fd=open(argv[1],O_RDONLY);
	pos=lseek(fd,0,SEEK_END);
	printf("Current cursor pos = %d\n",pos);
	close(fd);
}
