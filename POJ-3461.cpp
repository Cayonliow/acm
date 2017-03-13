#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;

int pi[1000100];
string A,B;
int gg=0;

void fail_function()
{
	//memset(pi,0,sizeof(pi));
	//int len=strlen(A);
	int len=A.length();
	pi[0]=-1;
	for(int i=1,cur_pos=-1;i<len;++i)
	{
		while(cur_pos>=0&&A[i]!=A[cur_pos+1])
		{
			cur_pos=pi[cur_pos];
		}
		
		if(A[i]==A[cur_pos+1])
		{
			++cur_pos;
		}
		
		pi[i]=cur_pos;
	}
	
}

void Match()
{
	int lenA=A.length();
	int lenB=B.length();
	
	for(int i=0,cur_pos=-1;i<lenB;++i)
	{
		while(cur_pos>=0&&B[i]!=A[cur_pos+1])
		{
			cur_pos=pi[cur_pos];
		}
		
		if(B[i]==A[cur_pos+1])
		{
			++cur_pos;
		}
		
		if(cur_pos+1==lenA)
		{
			cur_pos=pi[cur_pos];
			gg++;
		}
	}	
}

int main()
{
	int count;
	//while(scanf("%d%*c",&count)==1)
	scanf("%d%*c",&count);
//	{
		for(int i=0;i<count;i++)
		{
			getline(cin,A);
			getline(cin,B);
			
			fail_function();
			Match();
			printf("%d\n",gg);
			gg=0;
		}
//	}
}
