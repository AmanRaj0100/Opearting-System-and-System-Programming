#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>


int main()
{
	int A[2];
	int i;
	pipe(A);
	i=fork();
	if(i==0)
	{
		char rbuf[50];
		printf("Child Process\n");
		while(1)
		{
			read(A[0],rbuf,12);
			printf("Read data by child given by parent = %s\n",rbuf);			
		}
	}
	else
	{
		char wdata[50];
		printf("Parent Process\n");
		while(1)
		{
			scanf("%s",wdata);
			write(A[1],wdata,12);
		}
		printf("Parent writes and completes\n");
		wait(0);
	}
}		

