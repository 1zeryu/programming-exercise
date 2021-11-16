/*有12枚硬币。其中有11枚真币和一枚假币。假币和真币重量不同，
但不知道假币比真币轻还是重。现在，用一架天平称了这些币三次，
告诉你称的结果，请你找出假币并且确定假币是轻是重。*/ 

#include<stdio.h>
#include<string.h>
//编译预处理
//定义函数判断是否为假，采用枚举的思想，枚举硬币是轻时是否符合，重时是否符合light
char left[3][7];
char right[3][7];
char result[3][5];
bool isfake(char sub,bool light)
{
	for(int i=0;i<3;i++)
	{
		printf("%s",result[i]);
		if(light)	//定义为轻时情况 
		{
			switch(result[i][0])
			{
				case 'u':	
					if(strchr(left[i], sub)==NULL) return false;
				case 'e': if(strchr(left[i], sub)||strchr(right[i],sub))
				return false;
				case 'd':	if(strchr(right[i], sub)==NULL) return false;
			}
		}
		else
		{
			switch(result[i][0])
			{
			case 'u':	
					if(strchr(right[i], sub)==NULL) return false;
			case 'e': if(strchr(left[i], sub)||strchr(right[i],sub))
				return false;
			case 'd':	if(strchr(left[i], sub)==NULL) return false;
			}
		}
	}
	return true;
}
 
 //主函数用于输入称量数据和判断情况 
int main(void)
{
	for(int i=0;i<3;i++)
	{
		scanf("%s%s%s",left[i],right[i],result[i]);
	}
	for(int i=0;i<3;i++)
	{
		printf("%s %s %s\n",left[i],right[i],result[i]);
	}
	char j;
	for(j='A';j<='L';j++)
	{
		if(isfake(j, true))
		{
			printf("The faker is %c, and is light\n");
			break;
		}
		else if(isfake(j, false))
		{
			printf("The faker is %c , and is heavy\n");
			break;
		}
		printf("%c is not faker\n");
	}
	return 0;
}
