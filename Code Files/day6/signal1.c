#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void myHandler()
{
	printf("signal handled\n");
	printf("in myhandler function\n");
	printf("signal SIGLARM Handled\n");
}


int main()
{
	int cnt=0;
	signal(SIGALRM,SIG_DFL);//registering SIGALRM
	alarm(18);
	while(1)
	{
		printf("in while loop\n");
		cnt++;
		printf("count = %d\n",cnt);
		sleep(1);
	}

}
