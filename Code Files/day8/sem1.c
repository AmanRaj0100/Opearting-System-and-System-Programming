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
int SHMID,SEMID,i;
char *ptr;
char data[80]="IN AMAZON TRAINING SHARED MEMORY CONTROLLED BY SEMAPHORE";
SHMID=shmget(shmkey,0,0);
printf("SHMID = %d\n",SHMID);
SEMID=semget(semkey,0,0);
printf("SEMID = %d\n",SEMID);
printf("Process1 wants to write in shared memory\n");
printf("process1 trying to take semaphore\n");

s1.sem_num=0;//index
s1.sem_op=-1;
s1.sem_flg=0;
semop(SEMID,&s1,1);
printf("Process1 takes semaphore\n");
printf("Process1 using shared memory\n");
ptr=shmat(SHMID,0,0);
for(i=0;data[i]!='\0';i++)
{
	*(ptr+i)=data[i];
	printf("writring\n");
	usleep(500000);
}
*(ptr+i)='\0';

printf("Process1 completes writing\n");
printf("Process1 trying to releases semphore\n");
s1.sem_op=+1;
semop(SEMID,&s1,1);
printf("Process1 release semaphore\n");

}
