#include<stdio.h>
int main(void)
{
	int n,i,j;
	char a;
	scanf("%c",&a);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++){
			printf(" ");
		}
		for(j=1;j<=i;j++){
			printf("%c ",a);
		}
		printf("\n");
	}
	return 0;
}
