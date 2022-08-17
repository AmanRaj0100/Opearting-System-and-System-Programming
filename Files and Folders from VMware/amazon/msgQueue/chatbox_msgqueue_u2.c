//Chatbox User_2

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
	struct msgbuf m1,m2;
	key_t mqkey=0xff1a1b00;
	int i,mqid;
	mqid=msgget(mqkey,IPC_CREAT|0777);
	printf("Message Queue Id: %d\n",mqid);
	i=fork();
	if(i==0)
	{	while(1)
		{
			msgrcv(mqid,&m1,sizeof(m1),1111,0);
			printf("Message_Type: %ld\n",m1.mtype);
			printf("Message_Text: %s\n",m1.mtext);
		}
	}
	else
	{
		while(1)
		{
			m2.mtype=2222;
			scanf("%s",m2.mtext);
			msgsnd(mqid,&m2,sizeof(m2),0);
			printf("Message_Sent\n");
		}
	}
}
