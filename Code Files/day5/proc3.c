#include<stdio.h>
#include<unistd.h>

int main()
{
	int i,j,k,l;
	i=fork();
	j=fork();
	k=fork();
	l=fork();

	printf("hi\n");
	while(1);
}
