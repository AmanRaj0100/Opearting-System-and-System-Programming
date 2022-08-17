#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd,k,pos;
	char ch;
	fd=open(argv[1],O_RDONLY);
	pos=lseek(fd,0,SEEK_END);
	while(1)
	{
		read(fd,&ch,1);
		printf("%c",ch);
		pos=lseek(fd,-2,SEEK_CUR);
		if(pos == 0)
			break;
	}
	
		read(fd,&ch,1);
		printf("%c",ch);
	
	close(fd);
}
