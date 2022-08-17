#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd,cnt=1;
	char ch;
	fd=open(argv[1],O_RDONLY);
	while(1)
	{
		if(cnt<=10)
		{
			read(fd,&ch,1);
			printf("%c",ch);
			if(ch=='\n')
				cnt++;
		}
		else
			break;	
	}
	close(fd);
}		
