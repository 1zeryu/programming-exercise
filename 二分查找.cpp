#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef struct list{
	int a[MAX];
	int index;
}list; 

list* makempty()
{
	list* master=(list*)malloc(sizeof(list));
	master->index=0;
	return master;
}

void insert(list* master,int k)
{
	if(master->index>=MAX)
	{
		printf("你的数组已满");
		return; 
	}
	master->a[master->index]=k;
	master->index++;
	return;
}

int find(list* master,int k)
{
	int left=0,right=(master->index)-1;
	int mid;
	int num=0;
	for(;right>=left;)
	{
		mid=(left+right)/2;
		if(master->a[mid]==k)
		{
			num++;
			printf("已找到你的数据");
			return num;
		}
		else if(master->a[mid]<k)
		{
			left=mid+1;
			num++;
		}
		else
		{
			right=mid-1;
			num++;
		}
	}
	printf("未找到你的数据");
	return num;
}

int main(void)
{
	list* master=makempty();
	for(int i=0;i<10;i++)
	{
		insert(master,i);
	}
	int n;
	scanf("%d",&n);
	int num=find(master,n);
	printf("%d",num);
	return 0;
} 
