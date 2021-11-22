#include<stdio.h>
#include<stdlib.h>
int f(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}
int main(void)
{
	int a[1000];
	for(int i=0;i<1000;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,999,sizeof(int),f);
	int left=0,right=999;
	int try;
	try=a[left]+a[right];
	int re;
	scanf("%d",&re);
	while(try!=re)
	{
		if(try<re)
		{
			left++;
		}
		else
		{
			right--;
		}
		try=a[left]+a[right];
	}
	printf("%d+%d=%d",a[left],a[right],re);
	return 0;
}
