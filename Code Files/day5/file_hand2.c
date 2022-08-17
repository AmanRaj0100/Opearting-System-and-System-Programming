#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int i,k;
	char ch;
	printf("file handling\n");
	i=open("myfile.txt",O_RDONLY);//O_WRONLY, O_RDWR
	
	while(1)
	{
		k=read(i,&ch,1);
		if(k==0)
			break;
		else
			printf("%c",ch);
	}	

	close(i);
}
