#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	string number1;
	string number2;
	
	while(cin>>number1>>number2)
	{
		if(number1=="0"&&number2=="0")return 0;
		
		int n1[260]={0};
		int n2[260]={0};
		int start[600]={0};
		int mark=0;
		
		for(int u=0;u<number1.length();u++)
		{
			n1[u]=number1[number1.length()-u-1]-'0';
		
		}

		for(int u=0;u<number2.length();u++)
		{
			
			n2[u]=number2[number2.length()-u-1]-'0';
		}
		
		int length;
		if(number2.length()>number1.length())
		{
			length=number2.length();
		}
		else
		{
			length=number1.length();
		}
		

		for(int i=0;i<length;i++)
		{
			
				start[i]=start[i]+n1[i]+n2[i];
				if(start[i]>9)mark++;
				start[i+1]=start[i+1]+start[i]/10;
				start[i]=start[i]%10;

			
		}
		/*
		for(int i=length;i>=0;i--)
		{

			printf("%d",start[i]);
		}
		printf("\n");
		*/
		
		if(mark==0)
		{
			printf("No carry operation.\n");
		}
		
		else if(mark==1)
		{
			
				printf("%d carry operation.\n",mark);
		}
		else
		{
			printf("%d carry operations.\n",mark);	
		}
		
	

	} 

	return 0;
}
