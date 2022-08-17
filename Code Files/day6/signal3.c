#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void myHanlder2();//declaration
void myHandler1()
{
	printf("signal handled in myHandler1\n");
	printf("in myhandler1 function\n");
	signal(SIGINT,myHandler2);	
}

void myHandler2()
{
	printf("signal handled in myHandler2\n");
	printf("in myhandler2 function\n");
	signal(SIGINT,myHandler1);	
}


int main()
{
	int cnt=0;
	signal(SIGINT,myHandler1);
	while(1)
	{
		printf("in while loop\n");
		cnt++;
		printf("count = %d\n",cnt);
		sleep(1);
	}

}
