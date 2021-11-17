#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// 进行编译预处理

// 进行数据结构定义
typedef struct  eque{
	int exp;
	int coef;
	struct eque *next;
}eque;

typedef struct list{
	eque *head;
	int length;
}list;

// 进行函数结构
list* makempty();
void Insert(list *root,int exp, int coef);
void Printall(list *root);
//list* Add(list* root1,list* root*);
bool isempty(list* root);
int calc(list *root,int x);
void Error();

// 主函数部分
int main(void)
{
	
	list* root=makempty();
	for(int i=1;i<4;i++)
	{
		Insert(root,i,i);
	}
	Printall(root);
	printf("\n%d",calc(root,2));
	return 0;
}
// 函数定义部分
void Error()
{
	printf("指针内存申请失败");
	exit(-1);
}

list* makempty()
{
	list* root=(list*)malloc(sizeof(list));
	if(!root)
	{
		Error();
	}
	root->head=NULL;
	root->length=0;
	return root;
 } 
 
void Insert(list* root,int exp,int coef)
{
	eque *p=(eque*)malloc(sizeof(eque));
	if(!p)
	{
		Error();
	}
	p->coef=coef;
	p->exp=exp;
	p->next=NULL;
	if(root->length==0)
	{
		root->head=p;
		root->length++;
		return;
	}
	else
	{
		eque* q=root->head;
		if(q->exp<p->exp)
		{
			p->next=q;
			root->head=p;
			root->length++;
			return;
		}
		for(;q->next;q=q->next)
		{
			if(q->exp=p->exp)
			{
				q->coef=q->coef+p->coef;
				root->length++;
				return;
			}
			else if((q->exp)>(p->exp)&&(q->next->exp)<p->exp)
			{
				p->next=q->next;
				q->next=p;
				root->length++;
				return;
			}
		}
		q->next=p;
		root->length++;
		return;
	}
}

void Printall(list *root)
{
	if(root->length==0)
	{
		printf("the list is empty\n");
		return;
	}
	eque *p=root->head;
	for(;p->next;p=p->next)
	{
		printf("%d*x^%d+",p->coef,p->exp); 
	}
	printf("%d*x^%d",p->coef,p->exp);
	return;
 } 
 
 bool isempty(list* root)
 {
 	if(root->length==0)
 	{
 		printf("the list is empty");
		return true; 
	 }
	else return false;
 }
 int calc(list *root,int x)
 {
 	int sum=0;
 	if(isempty(root))
 	{
 		return 0;
	}
 	eque *p=root->head;
 	for(;p;p=p->next)
 	{
 		sum+=p->coef*pow(x,p->exp);
	 }
	return sum;
 }
 
// void Add()
// {
// 	
// }
