#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd1;
	fd1=open("f1",O_WRONLY);
	char data[40]={0};
	while(1)
	{
		scanf("%s",data);//hello hi
		write(fd1,data,strlen(data)+1);
		if(strcmp(data,"quit") == 0)
			break;
	}
	close(fd1);
	return 0;
}
