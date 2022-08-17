#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void * myfun1()
{
	int y,x=88;
	for(int i=0;i<200;i++)
	{
		printf("in myfun1 i = %d\n",i);
		printf("in myfun1 i = %d\n",i);
		printf("in myfun1 i = %d\n",i);
		printf("in myfun1 i = %d\n",i);
		if(i==50)
			y=x/0;
		usleep(5000);
	}
}

void * myfun2()
{
	for(int i=0;i<400;i++)
	{
		printf("in myfun2 i = %d \n",i);
		printf("in myfun2 i = %d \n",i);
		printf("in myfun2 i = %d \n",i);
		printf("in myfun2 i = %d \n",i);
		usleep(5000);
	}
}

void * myfun3()
{
	for(int i=0;i<300;i++)
	{
		printf("in myfun3 i = %d \n",i);
		printf("in myfun3 i = %d \n",i);
		printf("in myfun3 i = %d \n",i);
		printf("in myfun3 i = %d \n",i);
		usleep(5000);
	}
}

int main()
{
	pthread_t tid1,tid2,tid3;
	printf("in main\n");
	printf("before myfun fucntions called\n");
	pthread_create(&tid1,NULL,myfun1,NULL);
	pthread_create(&tid2,NULL,myfun2,NULL);
	pthread_create(&tid3,NULL,myfun3,NULL);

	pthread_join(tid1,NULL);	
	pthread_join(tid2,NULL);	
	pthread_join(tid3,NULL);	
	
	printf("after myfun fucntions called\n");
	printf("end of main function\n");
	printf("bye\n");
}
