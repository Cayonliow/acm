#include<iostream> 
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edge[105];
int llink[105], rlink[105];
bool used[105];

bool DFS(int now)
{
    for(int i=0;i<edge[now].size();++i) 
	{
        int nxt=edge[now][i];
        if(used[nxt])
		{
			continue;
		} 

        used[nxt] = true;
        if(rlink[nxt]==-1 || DFS(rlink[nxt])==true) 
		{
            llink[now]=nxt;
            rlink[nxt]=now;
            return true;
        }
    }
    return false;
}
int main()
{
    int n,m,k;
    while(scanf("%d", &n)&&n) 
	{
        for(int i=0;i<n;++i)
		{
			edge[i].clear();
		} 

        scanf("%d %d",&m,&k);
        int i,x,y;
        for(int j=0;j<k;++j) 
		{
            scanf("%d %d %d",&i,&x,&y);
            if(!x||!y)
			{
				continue;	
			}          
            
			edge[x].push_back(y);
        }
 
        int result=0;
        fill(llink,llink+n,-1);
        fill(rlink,rlink+m,-1);

        for(int i=0;i<n;++i) 
		{
            fill(used,used+m,false);
            if(DFS(i)==true)
			{
				++result;
			} 
        }

        printf("%d\n",result);
    }
}
