#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAXSIZE 100

/* 定义顺序表的结构，数组和数组长度last */
typedef struct array{
	int a[100];
	int last=0;
}array;

/* 创建顺序表方法，create空表 */
array* Create_empty(void)
{
	array* p=(array*)malloc(sizeof(array));
	p->last=0; 
	return p;
}

/* 创建insert方法，用于在特定位置插入元素 */
void Insert(array* p,int locate, int k) 
{
	if(p->last>=MAXSIZE)
	{
		printf("已经放不下了");		
		return;
	} 
	if(locate>p->last+1||locate<0)
	{
		printf("你的插入不合理"); 
		return;
	}
	int i;
	for(i=p->last;i>locate;i++)
	{
		p->a[i]=p->a[i-1];
	}
	p->a[locate]=k;
	p->last++;
	return;
}

/* 在数组中寻找元素并返回下标 */
int Find(array* p,int k)
{
	if(p->last==0)
	{
		printf("你的表为空表");
		return -1;
	}
	else
	{
		int i;
		for(i=0;i<p->last;i++)
		{
			if(p->a[i]==k)
			{
				return i;
			}
		}
	}
	printf("为找到相应的元素");
	return k; 
}

/* 创建delete函数，用于删除表中元素 */
void Delete(array* p,int locate)
{
	if(p->last==0)
	{
		printf("你的表为空表"); 
		return;
	}
	if(locate>=p->last||locate<0)
	{
		printf("你的删除不合格"); 
		return;
	}
	int i;
	for(i=locate;i<p->last;i++)
	{
		p->a[i]=p->a[i+1];
	}
	p->a[i]=0;
	p->last--;
	return;
}

/* 定义length方法，用于查找目前表的元素的个数 */
int length(array* p)
{
	int k=p->last;
	return k;
}

/* 定义查找给定数组的第k个元素 */ 
int Findkth(array* p,int n)
{
	return p->a[n-1];
}

/* 在主函数进行验证函数定义的真确性 */
int main(void)
{
	array* p=Create_empty();
	int i;
	for(i=0;i<50;i++)
	{
		Insert(p,i,i+1);
	}
	printf("%d",Find(p,1));
	printf("%d",Findkth(p,49));
	return 0;
} 
