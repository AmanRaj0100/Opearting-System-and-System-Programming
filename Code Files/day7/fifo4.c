#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int i,j,k;
	char rd[50],wd[50];
	i=open("f1",O_RDONLY);
	j=open("f2",O_WRONLY);
	k=fork();
	if(k==0)
	{
		while(1)
		{
			read(i,rd,50);
			printf("%s\n",rd);
		}
	}
		
	else
	{
		while(1)
		{
			scanf("%s",wd);
			write(j,wd,strlen(wd)+1);
		}
	}
	close(i);
	close(j);
}
	
