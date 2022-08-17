#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int i,j,k;
	i=fork();
	if(i==0)
	{
		printf("Process Id: %d\n",getpid());
		printf("Parent Process Id: %d\n",getppid());
	}
	else
	{
		j=fork();
		if(j==0)
		{
			printf("Process Id: %d\n",getpid());
			printf("Parent Process Id: %d\n",getppid());
		}
		else
		{
			k=fork();
			if(k==0)
			{
				printf("Process Id: %d\n",getpid());
				printf("Parent Process Id: %d\n",getppid());
			}
			else
			{
				wait(0);
				wait(0);
				wait(0);
				//while(1); - use this one for infinite loop and then check in another shell using pstree but disable wait() before
			}
		}
	
	}
}

