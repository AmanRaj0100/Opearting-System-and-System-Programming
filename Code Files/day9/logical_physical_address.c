#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int i;
	char A[50];

	i=fork();
	if(i==0)
	{

	printf("Child process\n");
	strcpy(A,"I am a child");
	printf("Address of A =  %p\n",A);
	printf("Data in A = %s\n",A);
	}
	else
	{
	
		printf("Child process\n");
		strcpy(A,"I am a Parent");
		printf("Address of A =  %p\n",A);
		printf("Data in A = %s\n",A);
		wait(0);
	}
}
