#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>

int main()
{
	int key=0x001a1b1c;
	int ID;
	char *ptr;
	ID=shmget(key,1400,IPC_CREAT|0777);
	printf("Shared memory ID = %d\n",ID);
	if(ID == -1)
		perror("shmget");
	ptr=shmat(ID,0,0);
	strcpy(ptr,"Hello Idris In USA");
	shmdt(ptr);


}
