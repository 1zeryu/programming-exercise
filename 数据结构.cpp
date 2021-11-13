/* 进行编译预处理 */
#include<stdio.h>
#include<stdlib.h>

/* 定义链表数据类型，用将链表放入list作为表头，length作为链表长度 */ 
typedef struct data{
	int k;
	struct data *next;
}data;

typedef struct list{
	data *point;
	int length;
}list;

/* 定义函数创建空链表 */
list* Create_empty(int num)
{
	list *head=(list*)malloc(sizeof(list));
	head->length=0;
	data *p=(data*)malloc(sizeof(data));
	p->k=num;
	p->next=NULL;
	head->point=p;
	head->length++;
	return head;
}

/* 定义函数用于查看链表是否为空 */
bool Isempty(list* head)
{
	if(head->length=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/* 定义函数用于查找 */
int Find(list* head, int location)
{
	data *p;
	p=head->point;
	int i;
	if(location>head->length)
	{
		printf("你的查找位置越界");
		return 0;
	}
	for(i=1;i<location;i++)
	{
		p=p->next;
	}
	return p->k;
}

/* 定义函数用于插入数据 */
void Insert(list* head,int location,int num)
{
	data* p;
	p=head->point;
	data* q=(data*)malloc(sizeof(data*));
	q->k=num;
	if(location==1)
	{
		q->next=head->point;
		head->point=q;
		head->length++;
		return;
	}
	if(location>head->length||location<1)
	{
		printf("你的插入有问题");
	}
	else
	{
		for(int i=1;i<location-1;i++)
		{
			p=p->next;
		}
		q->next=p->next;
		p->next=q;
		head->length++;
	}
	return;
}

/* 定义函数用于删除链表的节点 */ 
void Delete(list* head,int location)
{
	data *p,*q;
	p=head->point;
	if(location>head->length||location<1)
	{
		printf("你要删除的节点不存在");
	}
	if(location==1)
	{
		head->point=p->next;
		head->length--;
		return;
	}
	else
	{
		for(int i=1;i<location-1;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		free(q);
		head->length--;
	}
	return;
}

/* 定义函数用于返回链表的长度 */
int Length(list* head)
{
	return head->length;
}

/* 定义函数用于清空链表的节点 */
void clear(list* head)
{
	data *p,*q;
	p=head->point;
	q=p->next;
	for(;p;)
	{
		free(p);
		p=q;
		q=p->next;
	}
	head->length=0;
	head->point=NULL;
	return;
}

/* 定义函数用于打印链表中的数据 */
void Print(list* head)
{
	data* p=head->point;
	for(;p;p=p->next)
	{
		printf("%d\n",p->k);
	}
	return;
}

/* 主函数main */
int main(void)
{
	list* head=Create_empty(5);
	for(int i=0;i<10;i++)
	{
		Insert(head,i,i);
	}
	Delete(head,5);
	Print(head);
	printf("%d",head->length);
	return 0;
}
