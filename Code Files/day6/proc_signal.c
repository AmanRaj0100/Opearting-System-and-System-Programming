#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void myfun()
{
	printf("child completed and parent can exit now\n");
	exit(0);
}

int main()
{
	int i;
	printf("in main program\n");
	printf("beore fork\n");
	i=fork();
	if(i==0)
	{
		sleep(random()%30);
		printf("child process\n");
		printf("child process\n");
		printf("child process\n");
		printf("Child process ID in Child Process %d\n",getpid());
		printf("Parent process ID in Child Process %d\n",getppid());
		printf("end of child process\n");
	}
	else
	{
		printf("parent process\n");
		printf("parent process\n");
		printf("parent process\n");
		printf("Child process ID in Parent Process %d\n",i);
		printf("Parent process ID in Parent Process %d\n",getpid());
		printf("end of Parent process\n");
		signal(SIGCHLD,myfun);
		while(1)
		{
			printf("waiting for child\n");
			sleep(1);
		}
	}
}
