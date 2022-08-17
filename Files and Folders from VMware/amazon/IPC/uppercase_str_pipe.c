#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>


int main()
{
	int A[2],B[2];
	int i,j;
	pipe(A);
	pipe(B);
	i=fork();
	if(i==0)
	{
		char rbuf[50];
		printf("Child Process\n");
		while(1)
		{
			read(A[0],rbuf,12);
			printf("Read data by child given by parent = %s\n",rbuf);
			for (j = 0; rbuf[j]!='\0'; j++)
			{
				if(rbuf[j] >= 'a' && rbuf[j] <= 'z')
					rbuf[j] = rbuf[j] -32;
			}
			write(B[1],rbuf,12);
			printf("Child writes back");
			memset(rbuf,0,50);
		}
	}
	else
	{
		char wdata[50],rdata[50];
		printf("Parent Process\n");
		while(1)
		{
			scanf("%s",wdata);
			write(A[1],wdata,12);
			read(B[0],rdata,12);
			printf("Read data by parent from child = %s\n",rdata);
			memset(rdata,0,50);
		}
		printf("Parent writes and completes\n");
		wait(0);
	}
}		

