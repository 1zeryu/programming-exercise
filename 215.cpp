#include<stdio.h>
#include<string.h>
char* f(char* a)
{
	int i,j;
	int length=strlen(a);
	char b[1000];
	for(i=0,j=length-1;i<length,j>=0;i++,j--)
	{
		b[i]=a[j];
	}
	return b;
}
int main(void)
{
	char a[1000];
	gets(a);
	int length=strlen(a);
	int i;
	char* b=f(a);
	for(i=0;i<length;i++)
	{
		putchar(b[i]);
	}
	return 0;
}
