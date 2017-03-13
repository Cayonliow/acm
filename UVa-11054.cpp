#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
 
int comp[100010];
int in[100010];
bool vis[100010];
vector<int> sorted;
vector<int> Edges[100010];
vector<int> R_Edges[100010]; 

void DFS1(int x)
{
    vis[x]=true;
 
    for(int u=0;u<Edges[x].size();u++)
    {
    	 if(!vis[Edges[x][u]]) 
		 {
		 	DFS1(Edges[x][u]);
		 }
	}
       
    sorted.push_back(x);
}
 
void DFS2(int x, int c)
{
    vis [x]=false;
    comp [x]=c;
 
    for(int u=0;u<R_Edges[x].size();u++)
    {
    	if (vis[R_Edges[x][u]]) 
		{
			DFS2(R_Edges[x][u],c);
		}
	}      
}
 
int main()
{
    int testCase;
    scanf ("%d", &testCase);
 
    for(int yyy=0;yyy<testCase;yyy++)
	{
        int n,m;
        scanf("%d %d",&n,&m);
 
        for(int i=0;i<100010;i++) 
		{
       	 	Edges[i].clear();
       	 	R_Edges[i].clear();
    	}
    	
    	sorted.clear();
    	memset(vis,false,sizeof (vis));
   		memset(in,0,sizeof(in));
 
        for(int i=0;i<m;i++) 
		{
            int a,b;
            scanf("%d %d",&a,&b);
            Edges[a].push_back(b);
            R_Edges[b].push_back(a);
        }
 
        for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				DFS1(i);	
			}
		}

        int c = 0;
 
        for(int i=sorted.size()-1;i>=0;i--) 
		{
            if(vis[sorted[i]])
            {
            	DFS2(sorted[i],++c);
			}
                
        }
 
        for(int i=1;i<=n;i++) 
		{
            for(size_t j=0;j<Edges[i].size();j++) 
			{
                if(comp[i]!=comp[Edges[i][j]])
                {
                	in[comp[Edges[i][j]]]++;
				}
                    
            }
        }
 
        int cnt=0;
 
        for(int i=1;i<=c;i++)
        {
        	if(!in[i])
			{
				cnt++;
			} 
		}
            
        printf ("%d\n", cnt);
    }
 
    return 0;
}
