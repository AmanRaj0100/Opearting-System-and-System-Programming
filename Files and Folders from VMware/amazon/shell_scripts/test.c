#include<stdio.h>
#include<unistd.h>

int main()
{
	int i,j;
	printf("Hello and Welcome to Process Management Unit\n");
	printf("This is a user created process\n");
	i=getpid();
	j=getppid();
	printf("Process ID: %d\n",i);
	sleep(4);
	printf("Parent Process ID: %d\n",j);
	printf("End\n");
	printf("Bye\n");
	//while(1);
	return 0;
}
