#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int i,j;
	char data[50];
	printf("file handling\n");
	i=open("myfile.txt",O_WRONLY);//O_WRONLY, O_RDWR
	printf("i = %d\n",i);
	printf("Enter a string :: ");
	gets(data);
	write(i,data,strlen(data));
	close(i);
}
