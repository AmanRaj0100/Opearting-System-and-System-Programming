#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main()
{
	int fd,k;
	char ch;
	struct stat s1;
	fd=open("data.txt",O_RDONLY);
	fstat(fd,&s1);
	printf("size of file data.txt = %ld\n",s1.st_size);
	while(1)
	{
		k=read(fd,&ch,1);
		if(k == 0)
			break;
		else
			printf("%c",ch);
	}
	lseek(fd,0,0);
	while(1)
	{
		k=read(fd,&ch,1);
		if(k == 0)
			break;
		else
			printf("%c",ch);
	}
	lseek(fd,0,0);
	while(1)
	{
		k=read(fd,&ch,1);
		if(k == 0)
			break;
		else
			printf("%c",ch);
	}
	close(fd);
}
