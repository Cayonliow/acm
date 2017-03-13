#include <iostream>
#include<cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> g[510];
int m[510];
int v[510];

bool DFS(int number)
{
    for(int i=0;i<g[number].size();++i)
    {
        if(!v[g[number][i]])
        {
            v[g[number][i]]=1;
            if(m[g[number][i]]==-1 || DFS(m[g[number][i]]))
            {
                m[g[number][i]]=number;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n,k,x,y;
	int answer=0;
    
    while(scanf("%d %d",&n,&k)==2)
	{
        for(int i=0;i<n;++i)
		{
			g[i].clear();
		} 
        
		memset(m,-1,sizeof(m));
		
        for(int i=0;i<k;++i)
        {
            scanf("%d %d",&x,&y);
            g[x-1].push_back(y-1);
        }
        
        for(int i=0;i<n;++i) 
		{
            memset(v,0,sizeof(v));
            
			if(DFS(i))
			{
				answer++;
			} 
        }
    	
		printf("%d\n",answer); 
    }
    return 0;
}
