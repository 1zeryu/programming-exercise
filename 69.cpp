#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int m,n;
	scanf("%d%d",&m,&n);
	int i,j;
	int** a=(int**)malloc(sizeof(int*)*m);
	for(i=0;i<m;i++)
	{
		a[i]=(int*)malloc(sizeof(int)*n);
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		int count=0;
		int max=0;
		int start=0,end=0;
		int temp;
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1)
			{
				temp = j;
				while(a[i][j]==1&&j<n)
				{
					count++;
					j++;
				}
				if(max<count)
				{
					end=j-1;
					start=temp;
					max=count; 
					count=0;
				}
			}
		}
		if(max==0)
		{
			printf("-1 -1\n");
		}
		else printf("%d %d\n",start,end);
	}
	return 0;
}
