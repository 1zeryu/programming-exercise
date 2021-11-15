#include<stdio.h>
int main(void)
{
	int p,e,i;	//设置各个高峰天数 
	scanf("%d%d%d",&p,&e,&i);	 
	int d;	//设置起始天数 
	scanf("%d",&d);
	int k=d;	//设置全高峰参数，枚举数 
	for(i=d;(k-p)%23!=0;k++);
	for(;(k-e)%28!=0;k+=23);
	for(;(k-i)%33!=0;k=k+23*28);
	
	printf("%d",k);
	return 0;
}
