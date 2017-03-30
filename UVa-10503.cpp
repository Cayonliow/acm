#include<iostream>
#include<cstdio>
#include<cstring> 

using namespace std;

int n,m;
int i1,i2,d1,d2,p[20],q[20];
bool choose[20];

bool backtracking(int Len,int num)
{
	if(Len==n)
	{
		if(num==d1)	return true;

		else return false;
	}

	for(int i=0;i<m;++i)
	{
		if(choose[i])	continue;
		if(p[i]==num||q[i]==num)
		{
			choose[i]=true;
			bool ok;
			if(p[i]==num)
			{
				ok=backtracking(Len+1,q[i]);
			}	
			else
			{
				ok=backtracking(Len+1,p[i]);
			} 
			
			if(ok==true)
			{
				return true;
			} 
			choose[i]=false;
		}
	}
	return false;
}
int main()
{
	while(scanf("%d",&n)&&n&&scanf("%d",&m)) 
	{
        scanf("%d %d",&i1,&i2);
		scanf("%d %d",&d1,&d2);
		
		memset(choose,false,sizeof(choose));
        for(int i=0;i<m;++i) 
		{
            scanf("%d %d",&p[i],&q[i]);
        }

        if (backtracking(0,i2)==true)
		{
			printf("YES\n");
		}
        else
		{
			printf("NO\n");
		}
    }
}
