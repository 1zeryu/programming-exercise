#include<stdio.h>
int main(void)
{
	int p,e,i;	//���ø����߷����� 
	scanf("%d%d%d",&p,&e,&i);	 
	int d;	//������ʼ���� 
	scanf("%d",&d);
	int k=d;	//����ȫ�߷������ö���� 
	for(i=d;(k-p)%23!=0;k++);
	for(;(k-e)%28!=0;k+=23);
	for(;(k-i)%33!=0;k=k+23*28);
	
	printf("%d",k);
	return 0;
}
