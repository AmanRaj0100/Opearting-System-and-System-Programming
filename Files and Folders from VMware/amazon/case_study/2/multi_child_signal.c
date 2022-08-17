#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

void myfun()
{
	static int flag=0;
	flag++;
	if(flag==3)
	{
		printf("All child processes completed\n");
		printf("Parent exiting...\n");
		printf("End of Processes\n");
		exit(0);
	}
}

int main()
{
	int i,j,k;
	i=fork();
	if(i==0)
	{
		sleep(5);
		printf("First Child Process Id: %d\n",getpid());
		printf("Parent Process Id: %d\n",getppid());
	}
	else
	{
		j=fork();
		if(j==0)
		{
			sleep(10);
			printf("Second Child Process Id: %d\n",getpid());
			printf("Parent Process Id: %d\n",getppid());
		}
		else
		{
			k=fork();
			if(k==0)
			{
				sleep(15);
				printf("Third Child Process Id: %d\n",getpid());
				printf("Parent Process Id: %d\n",getppid());
			}
			else
			{
				signal(SIGCHLD,myfun);
				while(1)
				{
					printf("Waiting for the Child processes to finish\n");
					sleep(1);
				}
			}
		}
	
	}
}

