/*��12öӲ�ҡ�������11ö��Һ�һö�ٱҡ��ٱҺ����������ͬ��
����֪���ٱұ�����ỹ���ء����ڣ���һ����ƽ������Щ�����Σ�
������ƵĽ���������ҳ��ٱҲ���ȷ���ٱ��������ء�*/ 

#include<stdio.h>
#include<string.h>
//����Ԥ����
//���庯���ж��Ƿ�Ϊ�٣�����ö�ٵ�˼�룬ö��Ӳ������ʱ�Ƿ���ϣ���ʱ�Ƿ����light
char left[3][7];
char right[3][7];
char result[3][5];
bool isfake(char sub,bool light)
{
	for(int i=0;i<3;i++)
	{
		printf("%s",result[i]);
		if(light)	//����Ϊ��ʱ��� 
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
 
 //��������������������ݺ��ж���� 
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
