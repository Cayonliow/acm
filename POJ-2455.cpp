#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N, P, T;
int cap[210][210];
int flow[210][210];
int bottleneck[210];
int pre[210];

struct Edge
{
    int u;
    int v;
    int len;

}Edge[40010];

int MaxFlow(int middle)
{
    memset(cap,0,sizeof(cap));
    memset(flow,0,sizeof(flow));
    
    for (int i=0;i<P;++i) 
	{
        if (Edge[i].len<=middle)
        {
        	cap[Edge[i].u][Edge[i].v]=(cap[Edge[i].v][Edge[i].u]+=1);
		}
            
    }


    int result=0;
    while (1) 
	{
        memset(bottleneck,0,sizeof(bottleneck));
        queue<int> Q;
        Q.push(1);
        bottleneck[1] =0x3f3f3f3f;

        while(!Q.empty() && !bottleneck[N]) 
		{ 
            int current=Q.front();
			Q.pop();
            
			for(int next=1;next<=N;++next) 
			{
                if (bottleneck[next]==0 && cap[current][next]>flow[current][next]) 
				{
                    pre[next]=current;
                    Q.push(next);
                    bottleneck[next]=min(bottleneck[current],cap[current][next]-flow[current][next]);
                }
            }
        }
        
        if (bottleneck[N] == 0)
		{
			break;
		} 

        for(int cur=N;cur!=1;cur=pre[cur]) 
		{
            flow[pre[cur]][cur]+=bottleneck[N];
            flow[cur][pre[cur]]-=bottleneck[N];
        }
        
		result+=bottleneck[N];
    }
    return result;
}

int main()
{
    
    while(scanf("%d %d %d", &N, &P, &T)==3)
    {
		int u,v,c;
		int edge=0;
    	for (int i=0;i<P;++i) 
		{
        	scanf("%d %d %d", &Edge[i].u,&Edge[i].v,&Edge[i].len);
        	edge=max(edge,Edge[i].len);
    	}

    	int left=0;
		int right=edge;
		int middle;
    	while (left!=right) 
		{
        	middle=(left+right)/2;

        	if(MaxFlow(middle)>=T)
			{
				right=middle;
			}
        
			else
			{
				left=middle+1;
			}
    	}
    
		printf("%d\n",left);
	}
}

