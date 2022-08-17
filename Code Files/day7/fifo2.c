#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fd1;
	char buf[50];
	fd1=open("f1",O_RDONLY);
	while(1)
	{
		read(fd1,buf,50);
		if(strcmp(buf,"quit") == 0)
			break;
		printf("data = %s\n",buf);
	}
		close(fd1);
	return 0;
}
