//Chatbox User_1

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
			msgrcv(mqid,&m2,sizeof(m2),2222,0);
			printf("Message_Type: %ld\n",m2.mtype);
			printf("Message_Text: %s\n",m2.mtext);
		}
	}
	else
	{
		while(1)
		{
			m1.mtype=1111;
			scanf("%s",m1.mtext);
			msgsnd(mqid,&m1,sizeof(m1),0);
			printf("Message_Sent\n");
		}	
	}
}
