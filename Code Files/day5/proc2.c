#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int i;
	printf("Process Management\n");
	printf("in proc1 process\n");
	printf("Before fork is called\n");
	i=fork();
	if(i==0)
	{
		printf("child process\n");
		printf("child process\n");
		printf("Child process ID in child process %d\n",getpid());
		printf("Parent process ID in child process %d\n",getppid());//local systemd or main systemd
	
	}
	
	else
	{
		sleep(10);
		printf("parent process\n");
		printf("parent process\n");
		printf("Child process ID in Parent process = %d\n",i);
		printf("Parent process ID in Parent process = %d\n",getpid());
		printf("parent completes\n");
	}
	
	return 0;
}

