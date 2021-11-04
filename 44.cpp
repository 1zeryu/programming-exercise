#include<stdio.h>
int fib(int n)
{
	if(n==1||n==2)
	{
		return 1;
	}
	else return fib(n-1)+fib(n-2);
}
int main(void)
{
	int n;
	scanf("%d",&n);
	int num=fib(n);
	int i;
	for(i=2;i*i<=num;i++)
	{
		if(num%i==0)
		{
			printf("%d",num);
			return 0;
		}
	}
	printf("yes");
	return 0;
}
