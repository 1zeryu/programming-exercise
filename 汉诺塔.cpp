#include<stdio.h>
// 定义a为起始柱，b为中转柱，c为终点柱 
void Hanoi(int n,char a,char b,char c)
{
	if(n==1)
	{
		printf("%c -> %c\n",a,c); 
	}
	else
	{
		Hanoi(n-1,a,c,b);
		printf("%c -> %c\n",a,c);
		Hanoi(n-1,b,a,c);
	}
	return;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	char a='A',b='B',c='C';
	Hanoi(n,a,b,c);
	return 0;	
} 
