#include<stdio.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/ipc.h>


int main()
{
	key_t shmkey=0x00aabbcc;
	key_t semkey=0x00ddeeff;
	int SHMID,SEMID;
	
	SHMID=shmget(shmkey,3500,IPC_CREAT|0777);
	printf("SHMID = %d\n",SHMID);

	SEMID=semget(semkey,1,IPC_CREAT|0777);
	printf("SEMID = %d\n",SEMID);

	semctl(SEMID,0,SETVAL,1);

	printf("Process Creates Shared_memory and Semaphore\n");
	printf("Initial value for Semaphore is set\n");
}
