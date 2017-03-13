#include<iostream>
#include<cstdio>

int map[110][110];
int n, m, v, s, t, x, y;
int max_flow() {
    int maxflow = 0;
	int tn,tw,Qt;
    int pre[110], V[110];
    int Q[10010];
   
    while(1) 
	{
        int used[110]={0};
        for(int i=0;i<=n;i++)    
		{
			V[i]=0;
		}
        
		V[s]=10000000;
        Qt=0;
		Q[0]=s;
		pre[s]=s;
        for(int i=0;i<=Qt;i++) 
		{
            tn=Q[i];
			used[tn]=0;
            for(int j=1;j<=n;j++) 
			{
                tw=(V[tn]<map[tn][j])?V[tn]:map[tn][j];
                if(tw>V[j]) 
				{
                    V[j]=tw; 
					pre[j]=tn;
                    if(used[j]==0)
                        Q[++Qt]=j;
						used[j]=1;
                }
            }
        }
        if(V[t]==0)
		{
        	break;	
		}
        maxflow+=V[t];
        for(int i=t;i!=s;i=pre[i]) 
		{
            map[pre[i]][i]-=V[t]; 
			map[i][pre[i]]+=V[t];
        }
    }
    return maxflow;
}
int main() 
{
 
    int Case=1;
    while(scanf("%d",&n)==1 && n!=0) 
	{
        scanf("%d %d %d",&s,&t,&m);
        
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				map[i][j]=0;
			}
                
		}
            
        for(int i=0;i<m;i++) 
		{
            scanf("%d %d %d",&x,&y,&v);
            map[x][y]+=v;
            map[y][x]+=v;
        }
        
		printf("Network %d\nThe bandwidth is %d.\n\n", Case++, max_flow());
    
	}
   
}
