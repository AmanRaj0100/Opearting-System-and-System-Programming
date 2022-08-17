#include<stdio.h>
#include<fcntl.h>
int main()
{
	int i,j;
	printf("File Handling\n");
	i=open("f1.txt",O_RDONLY);//O_WRONLY, O_RDWR
	j=open("f2.txt",O_WRONLY);
	printf("i = %d\n",i);
	printf("j = %d\n",j);
	while(1);
return 0;
}
