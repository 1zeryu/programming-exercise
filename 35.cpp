#include<stdio.h>
bool f(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main(void)
{
	int n;
	scanf("%d",&n);
	int i,j;
	i=2,j=n-2;
	for(;;i++,j--)
	{
		if(f(i)&&f(j))
		{
			printf("%d %d",i,j);
			return 0;
		}
	}
	return 1;
}
