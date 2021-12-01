#include<stdio.h>
#include<stdlib.h>
void quicksort(int a[],int start,int end)
{
	if(start>=end)	return;
	int i=start,j=end;
	while(i<j)
	{
		while(i<j)
		{
			if(a[i]>=a[j])
			{
				a[i]^=a[j];
				a[j]^=a[i];
				a[i]^=a[j];
				break;
			}
			else
			{
				j--;
			}
		}
		while(i<j)
		{
			if(a[j]<a[i])
			{
				a[i]^=a[j];
				a[j]^=a[i];
				a[i]^=a[j];
				break;
			}
			else
			{
				i++;
			}
		}
	}
	quicksort(a,0,i-1);
	quicksort(a,i+1,end);
	return;
}
int main(void)
{
	int n;
	scanf("%d",&n);
	int *a=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)	scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)	printf("%d ",a[i]);
	return 0;
}
