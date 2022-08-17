#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd1;
	char buf[50]={0};
	fd1=open("f1",O_RDONLY);
	read(fd1,buf,50);
	printf("Process2 reads data = %s\n",buf);
	close(fd1);
	return 0;
}
