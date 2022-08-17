#include<stdio.h>
#include<unistd.h>

int main()
{
	int pagesize;
	pagesize=getpagesize();
	printf("page size =  %d\n",pagesize);
}
