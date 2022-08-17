#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	char ch;
	int k,fd1,nc=0,nw=0,nl=0;
	if(argc!=2)
	{
		printf("not enough argument passed, count not possible\n");
		exit(0);
	}
	fd1=open(argv[1],O_RDONLY);
	if(fd1==-1)
	{
		printf("Source file not found, copy not possible\n");
		exit(0);
	}
	else
	{
		while(1)
		{
			k=read(fd1,&ch,1);
			if(k==0)
				break;
			else
				if(ch==' '|| ch=='\n' || ch=='\t')
				{
					nw++;
				}
				if(ch=='\n')
				{
					nl++;
				}
				if(k!=0 || ch==' ' || ch=='\n')
				{ 
					nc++;
				}
		}
		close(fd1);
		printf("Number of char: %d\n",nc);
		printf("Number of words: %d\n",nw);
		printf("Number of lines: %d\n",nl);
		
	}
}
