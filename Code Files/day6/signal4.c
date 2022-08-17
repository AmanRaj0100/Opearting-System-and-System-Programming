#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void myHandler1()
{
	int flag;
	flag++;
	printf("signal handled in myHandler1\n");
	printf("in myhandler1 function flag = %d\n",flag);
	if(flag == 5)
		signal(SIGINT,SIG_DFL);
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
