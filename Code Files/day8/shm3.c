#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>

int main()
{
	int key=0x001a1b1c;
	int ID;
	char *ptr;
	char buf[50];
	ID=shmget(key,0,0);
	printf("Shared memory ID = %d\n",ID);
	if(ID == -1)
		perror("shmget");
	ptr=shmat(ID,0,0);
	strcpy(buf,ptr);
	printf("read data = %s\n",buf);
	shmdt(ptr);

	shmctl(ID,IPC_RMID,0);
}
