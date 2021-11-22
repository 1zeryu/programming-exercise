#include<stdio.h>
#include<math.h>
double f(double x)
{
	double re=x*x*x-5*x*x+10*x-80;
	return re;
}
int main(void)
{
	double err=1e-6;
	double x;
	double left=0,right=100;
	double mid=(left+right)/2;
	x=mid;
	while(fabs(f(x)-0)>1e-6)
	{
		if(f(x)>0)
		{
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
		mid=(right+left)/2;
		x=mid;
	}
	printf("%lf",x);
	return 0;
}
