#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>

struct msgbuf
{
	long mtype;
	char mtext[12];
};

int main()
{
	int key=0x234bba;
	int id,i;
	id=msgget(key,IPC_CREAT|0777);
	printf("Message queue ID = %d\n",id);
	i=fork();
	if(i==0)
	{
		struct msgbuf msg1;
		while(1)
		{
			msgrcv(id,&msg1,sizeof(msg1),1111,0);
			printf("%s\n",msg1.mtext);
		}
	}
	else
	{
		
		struct msgbuf msg2;
		msg2.mtype=2222;
		while(1)
		{
			gets(msg2.mtext);
			msgsnd(id,&msg2,sizeof(msg2),0);
		}
	}

}
