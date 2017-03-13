#include<iostream>
#include<cstring>
#include<cstdio>

int calLove(char *string)
{
	int i;
	int length=strlen(string)-1;
	int count[30];
	int number=0;
	int divide[100];
	for(i=0;i<length;i++)
	{
		if(string[i]>='a'&&string[i]<='z')
		{
			count[i]=(int)string[i]-'a'+1;
			//printf("%d ",count[i]);
			number=number+count[i];
		}
			
		if(string[i]>='A'&&string[i]<='Z')
		{
			count[i]=(int)string[i]-'A'+1;
			//printf("%d ",count[i]);
			number=number+count[i];
		}
	}
	//printf("\n");
	
	while(number>9)
	{
		int y=0;
		int tmp=0;
		while(number>0)//for(i=0;i<2;i++)
		{
			divide[y]=number%10;
			number=number/10;
			y++;
		}
		//number=0;
		for(i=0;i<y;i++)
		tmp=tmp+divide[i];	
		
		number=tmp;
	}
	
	return number;
}
int main()
{
	char s1[30], s2[30];
	double result;
	while(fgets(s1,sizeof(s1),stdin)!=0)
	{
		fgets(s2,sizeof(s2),stdin);
		
			int a1=calLove(s1);
			int a2=calLove(s2);
		//printf("%d %d\n",a1,a2);
		
		if(a1>a2)
			result=(double)a2/a1*100;
		
		if(a2>a1)
			result=(double)a1/a2*100;
		
		if(a1==a2)
			result=100;
	
	printf("%.2f %%\n",result);
	
	
	}
	return 0;

}

