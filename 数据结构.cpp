#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAXSIZE 100

/* ����˳���Ľṹ����������鳤��last */
typedef struct array{
	int a[100];
	int last=0;
}array;

/* ����˳�������create�ձ� */
array* Create_empty(void)
{
	array* p=(array*)malloc(sizeof(array));
	p->last=0; 
	return p;
}

/* ����insert�������������ض�λ�ò���Ԫ�� */
void Insert(array* p,int locate, int k) 
{
	if(p->last>=MAXSIZE)
	{
		printf("�Ѿ��Ų�����");		
		return;
	} 
	if(locate>p->last+1||locate<0)
	{
		printf("��Ĳ��벻����"); 
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

/* ��������Ѱ��Ԫ�ز������±� */
int Find(array* p,int k)
{
	if(p->last==0)
	{
		printf("��ı�Ϊ�ձ�");
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
	printf("Ϊ�ҵ���Ӧ��Ԫ��");
	return k; 
}

/* ����delete����������ɾ������Ԫ�� */
void Delete(array* p,int locate)
{
	if(p->last==0)
	{
		printf("��ı�Ϊ�ձ�"); 
		return;
	}
	if(locate>=p->last||locate<0)
	{
		printf("���ɾ�����ϸ�"); 
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

/* ����length���������ڲ���Ŀǰ���Ԫ�صĸ��� */
int length(array* p)
{
	int k=p->last;
	return k;
}

/* ������Ҹ�������ĵ�k��Ԫ�� */ 
int Findkth(array* p,int n)
{
	return p->a[n-1];
}

/* ��������������֤�����������ȷ�� */
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
