#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{

	int A[2],B[2];
	int i;
	pipe(A);//return two descriptors A[0] -> Read end and A[1] -> write end
	pipe(B);
	i=fork();

	if(i==0)
	{
		char rbuf[50];
		printf("child process\n");
		while(1)
		{
		read(A[0],rbuf,12);//hello
		printf("Read data by child from parent = %s\n",rbuf);
		for(int i=0;rbuf[i]!='\0';i++)
			rbuf[i]=rbuf[i]-32;
		write(B[1],rbuf,12);
		printf("child writes back\n");
		memset(rbuf,0,50);
		}
	}
	else
	{
		char wdata[50],rdata[50];
		printf("Parent process\n");
		while(1)
		{
			scanf("%s",wdata);//hello
			write(A[1],wdata,12);
			read(B[0],rdata,12);
			printf("Read data by parent from child = %s\n",rdata);
			memset(rdata,0,50);
		
		}
		printf("Parent writes and completes\n");
		wait(0);
	}

}
