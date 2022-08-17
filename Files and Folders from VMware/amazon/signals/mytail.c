#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int k,pos,fd,cnt=0;
	char ch;
	fd=open(argv[1],O_RDONLY);
	lseek(fd,0,SEEK_END);
	while(1)
	{
		read(fd,&ch,1);
		if(cnt<=10)
		{
			pos=lseek(fd,-2,SEEK_CUR);
			if(ch=='\n')
				cnt++;
		}
		else
		{
			lseek(fd,pos,SEEK_SET);
			k=read(fd,&ch,1);
			printf("%c",ch);
			if(k==0)
				break;
		}
	}
	close(fd);
}		
