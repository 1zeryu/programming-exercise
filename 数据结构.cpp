/* ���б���Ԥ���� */
#include<stdio.h>
#include<stdlib.h>

/* ���������������ͣ��ý��������list��Ϊ��ͷ��length��Ϊ������ */ 
typedef struct data{
	int k;
	struct data *next;
}data;

typedef struct list{
	data *point;
	int length;
}list;

/* ���庯������������ */
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

/* ���庯�����ڲ鿴�����Ƿ�Ϊ�� */
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
/* ���庯�����ڲ��� */
int Find(list* head, int location)
{
	data *p;
	p=head->point;
	int i;
	if(location>head->length)
	{
		printf("��Ĳ���λ��Խ��");
		return 0;
	}
	for(i=1;i<location;i++)
	{
		p=p->next;
	}
	return p->k;
}

/* ���庯�����ڲ������� */
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
		printf("��Ĳ���������");
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

/* ���庯������ɾ������Ľڵ� */ 
void Delete(list* head,int location)
{
	data *p,*q;
	p=head->point;
	if(location>head->length||location<1)
	{
		printf("��Ҫɾ���Ľڵ㲻����");
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

/* ���庯�����ڷ�������ĳ��� */
int Length(list* head)
{
	return head->length;
}

/* ���庯�������������Ľڵ� */
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

/* ���庯�����ڴ�ӡ�����е����� */
void Print(list* head)
{
	data* p=head->point;
	for(;p;p=p->next)
	{
		printf("%d\n",p->k);
	}
	return;
}

/* ������main */
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
