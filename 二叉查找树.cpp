#include<stdio.h>
#include<stdlib.h>
// ���б���Ԥ����
// ������������
typedef struct tree{
	int num;
	tree *left;
	tree *right;
}tree;
 
// �������� 
tree* make(int num);
void Insert(tree *root,int num);
tree* Delete(tree *root,int num);
tree* Findmax(tree *root);
tree* Findmin(tree *root);
int Find(tree *root);
void Print(tree *root);

// ������
int main(void)
{
	tree *root=make(5);
	Insert(root,6);
	Insert(root,4);
	Insert(root,9);
	Insert(root,9);
	Delete(root,4);
	Print(root);
	return 0;
} 

// ��������
tree* make(int num)
{
	tree *p=(tree*)malloc(sizeof(tree));
	if(!p)
	{
		printf("�����ڴ�ռ�ʧ��");
		exit(-1);
	}
	p->left=NULL;
	p->right=NULL;
	p->num=num;
	return p;
} 

void Insert(tree *root,int num)
{
	if(root->num>num&&root->left==NULL)
	{
		tree *p=make(num);
		root->left=p;
	}
	else if(root->num<num&&root->right==NULL)
	{
		tree *p=make(num);
		root->right=p;
	}
	else
	{
		if(root->num>num)
		{
			Insert(root->left,num);
		}
		else if(root->num<num)
		{
			Insert(root->right,num);
		}
	}
	return;
}

// ����ǰ���������ӡ�������� 
void Print(tree *root)
{
	if(!root)
	{
		return;
	}
	else 
	{
		printf("%d\n",root->num);
	}
	Print(root->left);
	Print(root->right);
	return;
}

tree* Findmax(tree *root)
{
	tree *p=root;
	for(;p->right;p=p->right);
	return p;
}

tree* Findmin(tree *root)
{
	tree *p=root;
	for(;p->left;p=p->left);
	return p;
}

tree* Find(tree *root,int num)
{
	tree *p=root;
	if(p->num==num)
	{
		return p;
	}
	else
	{
		if(p->num>num&&p->left)
			return Find(p->left,num);
		if(p->num<num&&p->right)
		{
			return Find(p->right,num);
		}
	}
	printf("δ�ҵ�");
	return NULL;
}

tree* Delete(tree *root,int num)
{
	if(root==NULL)
	{
		printf("element not found");
		return root;
	}
	else if(root->num>num)
	{
		root->left=Delete(root->left,num);
	}
	else if(root->num<num)
	{
		root->right=Delete(root->right,num);
	}
	else
	{
		if(root->left&&root->right)
		{
			tree *p=Findmin(root->right);
			root->num=p->num;
			root->right=Delete(root->right,root->num);
		}
		else
		{
			tree *p=root;
			if(p->left==NULL)	root=root->left;
			else if(p->right==NULL) root=root->right;
			free(p);
		}
	}
	return root;
}
