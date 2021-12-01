#include<stdio.h>
#include<stdlib.h>
void Merge(int a[],int start,int end)
{
	int i=start,mid=(start+end)/2;
	int j=1+mid;
	int *temp=(int*)malloc(sizeof(int)*(end-start+1));
	int size=0;
	while(i<=mid&&j<=end)
	{
		if(a[i]<=a[j])
		{
			temp[size]=a[i];
			i++,size++;
		}
		else if(a[i]>a[j])
		{
			temp[size]=a[j];
			j++,size++;
		}
	}
	if(i<=mid)
	{
		for(;i<=mid;i++)
		{
			temp[size]=a[i];
			size++;
		}
	}
	else
	{
		for(;j<=end;j++)
		{
			temp[size]=a[j];
			size++;
		}
	}
	size=0;
	for(int k=start;k<=end;k++,size++)
	{
		a[k]=temp[size];
	}
	return;
}
void Mergesort(int a[],int start,int end)
{
	if(start>=end)	return;
	int mid=(start+end)/2;
	Mergesort(a,start,mid);
	Mergesort(a,mid+1,end);
	Merge(a,start,end);
}
int main(void)
{
	int n;
	scanf("%d",&n);
	int *a=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)	scanf("%d",&a[i]);
	Mergesort(a,0,n-1);
	for(int i=0;i<n;i++)	printf("%d ",a[i]);
	return 0;
}
