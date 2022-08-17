#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct msgbuf
{
	int mtype;
	char mtext[12];
};

int main()
{
	struct msgbuf m1;
	key_t mqkey=0xff1a1b00;
	int mqid;
	mqid=msgget(mqkey,IPC_CREAT|0777);//IPC_CREAT
	printf("message queue ID = %d\n",mqid);

	m1.mtype=1234;
	strcpy(m1.mtext,"Hello World");
	msgsnd(mqid,&m1,sizeof(m1),0);//0 WAIT  , IPC_NOWAIT
	printf("message1 sent\n");
	
	m1.mtype=3456;
	strcpy(m1.mtext,"Hello India");
	msgsnd(mqid,&m1,sizeof(m1),0);//0 WAIT  , IPC_NOWAIT
	printf("message2 sent\n");
}
