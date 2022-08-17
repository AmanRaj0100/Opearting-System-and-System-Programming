//Traffic Signal Receiver

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
	int mqid,count=60;
	mqid=msgget(mqkey,IPC_CREAT|0777);
	printf("Message Queue Id: %d\n",mqid);
	while(1)
	{
		printf("RED %d\n",count);
		count--;
		sleep(1);

		msgrcv(mqid,&m,sizeof(m),111,IPC_NOWAIT);
		
		//printf("%s\n",m.mtext);
		
		if(strcmp(m.mtext,"green") == 0)
		{
			count=60;
			int flag1=60;
			while(1)
			{
				printf("GREEN %d\n",flag1);
				flag1--;
				sleep(1);
				if(flag1==-1)
					break;
			}
			memset(m.mtext,0,12);
		}

		if(strcmp(m.mtext,"amber") == 0)
		{
			count=60;
			int flag2=60;
			while(1)
			{
				printf("AMBER %d\n",flag2);
				flag2--;
				sleep(1);
				if(flag2==-1)
					break;
			}
			memset(m.mtext,0,12);
		}
		if(count==-1)
			count=60;
	}
}












	/*i=fork();
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
	}*/

