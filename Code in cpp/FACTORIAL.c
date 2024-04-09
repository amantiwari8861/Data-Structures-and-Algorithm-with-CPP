#include<stdio.h>
int factorial(int num)
{
	if(num>0)
	{
		return num*factorial(num-1);
	}
	else{
		return 1;
	}
}
void main()
{		int fact=1,num;
		printf("enter the number\n");
		scanf("%d",&num);
		fact=factorial(num);
		printf("factorial is %d",fact);
}