#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>

struct msgbuf
{
	int mtype;
	char mtext[12];
};

int main()
{
	struct msgbuf m;
	key_t mqkey=0xff1a1b00;
	int mqid,k;
	mqid=msgget(mqkey,0);
	printf("message queue ID = %d\n",mqid);

	while(1)
	{
		k=msgrcv(mqid,&m,sizeof(m),0,IPC_NOWAIT);
		if(k==-1)
		{
			perror("");
			printf("process will do something else\n");
			printf("process will do something else\n");
			printf("process will do something else\n");
			sleep(1);
		}
		else
		{
		printf("Message type = %d\n",m.mtype);//1234
		printf("Message text = %s\n",m.mtext);//hello world
		break;
		}
	}
}
