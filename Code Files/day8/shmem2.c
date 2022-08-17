#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int shmid;
	char *p;
	key_t shmkey=0xffaabb00;
	shmid=shmget(shmkey,0,0);
	printf("Shared memory ID = %d\n",shmid);
	p=shmat(shmid,0,SHM_RDONLY);
	//printf("%s\n",p);
	
	for(int i=0;*(p+i)!='\0';i++)
	{
		printf("%c\n",*(p+i));
		//sleep(1);
	}
	shmdt(p);

}
