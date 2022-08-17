#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd,k,pos;
	char ch;
	fd=open(argv[1],O_RDONLY);
	pos=lseek(fd,25,SEEK_SET);
	printf("Current cursor pos = %d\n",pos);
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
