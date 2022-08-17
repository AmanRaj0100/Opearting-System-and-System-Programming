#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void * myfun1(void *v)
{
	for(int i=0;i<300;i++)
	{
		printf("In myfun1, i = %d\n",i);
	}
	usleep(5000);
}

void * myfun2(void *w)
{
	for(int i=0;i<400;i++)
	{
		printf("In myfun2, i = %d\n",i);
	}
	usleep(5000);
}

void * myfun3(void *x)
{
	for(int i=0;i<500;i++)
	{
		printf("In myfun3, i = %d\n",i);
	}
	usleep(5000);
}

void * myfun4(void *y)
{
	int k,x=44;
	for(int i=0;i<600;i++)
	{
		printf("In myfun4, i = %d\n",i);
		if(i==300)
			k=x/0;
	}
	usleep(5000);
}

void * myfun5(void *z)
{
	for(int i=0;i<700;i++)
	{
		printf("In myfun5, i = %d\n",i);
	}
	usleep(5000);
}


int main()
{
	pthread_t tid1,tid2,tid3,tid4,tid5;

	printf("In Main Function\n");
	printf("Before myfun functions are called\n");

	pthread_create(&tid1,NULL,myfun1,NULL);
	pthread_create(&tid2,NULL,myfun2,NULL);
	pthread_create(&tid3,NULL,myfun3,NULL);
	pthread_create(&tid4,NULL,myfun4,NULL);
	pthread_create(&tid5,NULL,myfun5,NULL);
	
	printf("Thread ID of myfun1 = %ld\n",tid1);	
	printf("Thread ID of myfun2 = %ld\n",tid2);	
	printf("Thread ID of myfun3 = %ld\n",tid3);	
	printf("Thread ID of myfun4 = %ld\n",tid4);	
	printf("Thread ID of myfun5 = %ld\n",tid5);
	
	pthread_join(tid1,NULL);	
	pthread_join(tid2,NULL);	
	pthread_join(tid3,NULL);	
	pthread_join(tid4,NULL);	
	pthread_join(tid5,NULL);
	
	printf("After myfun functions are called\n");
	printf("End of Main Funtion\n");
	printf("Bye\n");	
}
