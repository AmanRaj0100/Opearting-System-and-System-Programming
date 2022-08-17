#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd1;
	fd1=open("f1",O_WRONLY);
	write(fd1,"HELLO AMAZON",12);
	printf("Process1 writes and finishes\n");
	close(fd1);
	return 0;
}
