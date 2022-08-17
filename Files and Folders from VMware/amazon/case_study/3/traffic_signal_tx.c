//Traffic Signal Transmitter

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>

struct msgbuf
{
	long int mtype;
	char mtext[12];
};


int main()
{
	struct msgbuf m;
	key_t mqkey=0xff1a1b00;
	int mqid;
	mqid=msgget(mqkey,0);
	printf("Message Queue Id: %d\n",mqid);
	while(1)
	{
		m.mtype=111;
		scanf("%s",m.mtext);
		msgsnd(mqid,&m,sizeof(m),0);
		//printf("%s\n",m.mtext);
	}
}
