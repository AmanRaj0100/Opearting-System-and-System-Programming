#include<stdio.h>
#include "perfect.h"
#include "palindrome.h"


int main()
{

	int num1;
	printf("Enter the number to check:: ");
	scanf("%d",&num1);

	if(isPerfect(num1))
	{
		printf("Given number is perfect\n");
	}
	else
	{
		printf("Given number is not perfect\n");
	}
	
	if(isPalindrome(num1))
	{
		printf("Given number is palindrome\n");
	}
	else
	{
		printf("Given number is not Palindrome\n");
	}
}
