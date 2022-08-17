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
char *ptr,ch;
SHMID=shmget(shmkey,0,0);
printf("SHMID = %d\n",SHMID);
SEMID=semget(semkey,0,0);
printf("SEMID = %d\n",SEMID);
printf("Process3 wants to read in shared memory\n");
printf("process3 trying to take semaphore\n");

s1.sem_num=0;
s1.sem_op=-1;
s1.sem_flg=0;
semop(SEMID,&s1,1);
printf("Process3 takes semaphore\n");
printf("Process3 using shared memory\n");
ptr=shmat(SHMID,0,0);
i=0;
while(ch=*(ptr+i))
{
printf("%c",ch);
fflush(stdout);
i++;	
usleep(500000);
}
printf("\n");

printf("Process3 completes reading\n");
printf("Process3 trying to releases semphore\n");
s1.sem_op=+1;

semop(SEMID,&s1,1);
printf("Process2 release semaphore\n");

}
