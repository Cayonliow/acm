#include<iostream> 
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int num[110];
int store[110];
int cap[110][110];
int maxflow[110][110];
int p[110];
int n,m,b,d;

int EK()
{
	queue<int >q;
	int f;
	memset(maxflow,0,sizeof(maxflow));
	f=0;
	while(1)
	{
		
		memset(store,0,sizeof(store));
		store[0] = 0x3f3f3f3f;
		q.push(0);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=0;i<=n+1;i++)
			{
				if(!store[i] && cap[u][i]>maxflow[u][i])
				{
					p[i]=u;
					q.push(i);
					store[i]=min(store[u],cap[u][i]-maxflow[u][i]);
				}
			}
		}
		
		if(store[n+1]==0)
		{
			break;
		}
		
		for(int i=n+1;i;i=p[i])
		{
			maxflow[p[i]][i]+=store[n+1];
			maxflow[i][p[i]]-=store[n+1];
		}
		
		f+=store[n+1];
	}
	
	return f;
}

int main()
{
	int x,y,z;
	while(scanf("%d",&n)==1)
	{
		memset(cap,0,sizeof(cap));
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		
		scanf("%d",&m);
		
		for(int j=0;j<m;j++)
		{
			scanf("%d %d %d",&x,&y,&z);
			cap[x][y] = z;
			cap[x][y] = min(cap[x][y],min(num[x],num[y]));
		}
		
		scanf("%d %d",&b,&d);
		
		for(int j=0;j<b;j++)
		{
			scanf("%d",&x);
			cap[0][x] = num[x];
		}
		
		for(int j=0;j<d;j++)
		{
			scanf("%d",&x);
			cap[x][n+1] = num[x];
		}
		
		
		
		printf("%d\n",EK());
	}
	return 0;
}
