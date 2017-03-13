#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n,cut;
int link[110][110];
int depth[110],low[110],used[110];

int DFS(int node,int d,int parent) 
{
	int back=1000;
	int son=0; 
	int flag = 0;
	int tmp; 
	depth[node] = d;
	
	for(int i=1;i<=n;i++) 
	{
		if(link[node][i]==1)
		{
			if(used[i]==0) 
			{
				used[i]=1;
				tmp=DFS(i,d+1,node);
				if(tmp>=d)
				{
					flag=1;
				}
				
				if(back>=tmp)
				{
					back=tmp;
				}
					
				//back = back < tmp ? back : tmp;
				son++;
			} 
			
			else 
			{
				if(i!=parent)
				{
					if(back>=depth[i])
					{
						back=depth[i];
					}
					//back = back < depth[i] ? back : depth[i];
				}
					
			}
		}
	}
	
	low[node]=back;
	if(node==1) 
	{
		if(son > 1)
		{
			cut++;
		}	
	} 
	
	else 
	{
		cut += flag;
	}
	
	return low[node];
}

int main() 
{
	int x, y;
	char c;
	
	while(scanf("%d",&n)==1&&n!=0)
	{
		memset(link, 0, sizeof(link));
		memset(depth, 0, sizeof(depth));
		memset(low, 0, sizeof(low));
		memset(used, 0, sizeof(used));
		
		while(scanf("%d",&x)==1&&x!=0) 
		{
			while(scanf("%d%c",&y,&c)==2) 
			{
				link[x][y]=1;
				link[y][x]=1;
				if(c=='\n')
				{
					break;
				}	
			}
		}
		used[1]=1;
		cut=0;
		DFS(1,1,0);
		printf("%d\n",cut);
	}
    return 0;
}
