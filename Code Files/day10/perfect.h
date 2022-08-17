#include<stdio.h>

int isPerfect(int num)
{
	int i, sum=0;
	printf("In is perfect function\n");
	
	for(int i=1;i<=num/2;i++)
	{
		if(num%i == 0)
			sum=sum+i;
	}

	if(sum == num)
		return 1;
	else
		return 0;
}
