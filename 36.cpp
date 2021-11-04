#include<stdio.h>
#include<stdlib.h>
int inc (const void * a,const void *b)
{
	return * (int * )b-* (int *)a;
}
int main(void)
{
	int n;
	scanf("%d",&n);
	int a[25][25];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	int* b=(int*)malloc(sizeof(int)*(2*n+2));
	int num=0;
	for(i=0;i<n;i++)
	{
		int sum=0;
		for(j=0;j<n;j++)
		{
			sum+=a[i][j];
		}
		b[num]=sum;
		num++;
		sum=0;
		for(j=0;j<n;j++)
		{
			sum+=a[j][i];
		}
		b[num]=sum;
		num++;
	}
	int sum=0;
	for(i=0,j=0;i<n,j<n;i++,j++)
	{
		sum+=a[i][j];
	}
	b[num]=sum;
	num++;
	sum=0;
	for(i=0,j=n-1;i<n,j>=0;i++,j--)
	{
		sum+=a[i][j];
	}
	b[num]=sum;
	qsort(b,2*n+2,sizeof(int),inc);
	for(i=0;i<2*n+2;i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}
