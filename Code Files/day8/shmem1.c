#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>


int main()
{
	int shmid;
	char *p;
	key_t shmkey=0xffaabb00;
	shmid=shmget(shmkey,980,IPC_CREAT|0777);
	printf("Shared memory ID = %d\n",shmid);
	p=shmat(shmid,0,0);//0 -> read and write  SHM_RDONLY ->Read only
	strcpy(p,"shared memory inter process communication mechanism in linux kernel");
	shmdt(p);
}
