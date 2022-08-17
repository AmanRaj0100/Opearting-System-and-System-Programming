#include<stdio.h>
#include<unistd.h>

int main()
{
	int cnt=0;
	alarma(15);
	while(1)
	{
		printf("In While Loop\n");
		printf("Count= %d\n",cnt++);
		sleep(1);
	}
}
