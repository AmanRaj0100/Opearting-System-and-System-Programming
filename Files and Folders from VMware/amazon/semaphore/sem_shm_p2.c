#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<unistd.h>

int main()
{
	int shmkey=0x00aabbcc;
	int semkey=0x00ddeeff;
	struct sembuf s1;
	int SHMID,SEMID,i=0;
	char *ptr,ch;

	SHMID=shmget(shmkey,0,0);
	printf("SHMID = %d\n",SHMID);
	SEMID=semget(semkey,0,0);
	printf("SEMID = %d\n",SEMID);
 
	printf("Process_2 wants to read from  Shared_memory\n");
	printf("Process_2 trying to take the semaphore\n");

	s1.sem_num=0;//index
	s1.sem_op=-1;
	s1.sem_flg=0;
	semop(SEMID,&s1,1);

	printf("Process_2 takes semaphore\n");
	printf("Process_2 is using Shared_memory\n");

	ptr=shmat(SHMID,0,SHM_RDONLY);
	
	while(ch=*(ptr+i))
	{
		printf("%c",ch);
		fflush(stdout);
		i++;
		usleep(500000);
	}
	printf("\n");
	
	printf("Process_2 completed reading\n");
	printf("Process_2 trying to release semaphore\n");

	s1.sem_op=+1;
	semop(SEMID,&s1,1);

	printf("Process_2 released semaphore\n");
}
