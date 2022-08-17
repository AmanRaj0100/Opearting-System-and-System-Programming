#include<stdio.h>

int isPalindrome(int num)//9687
{
	int numc=num,revnum=0,rem;
	printf("In is palindrome function\n");
	
	while(num)//0
	{
		rem=num%10;//rem = 9%10  9
		revnum=revnum*10+rem;//revnum=786*10+9= 7869
		num=num/10;//num=9/10  0

	}

	if(revnum == numc)
		return 1;
	else
		return 0;
}

