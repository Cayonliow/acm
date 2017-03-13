#include<iostream> 
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct EDGE
{
    int A;
    int B;
    int L;
}edge[15010];

int Set[1010];

bool cmp(EDGE &A,EDGE &B) 
{
    return A.L<B.L;
}

void Ini(int N)
{
    for(int i=1;i<=N;++i)
    {
    	Set[i]=i;
	}
        
}
int Find_Root(int x)
{
    if(x==Set[x])
    {
    	return x;
	}
        
    return Set[x]=Find_Root(Set[x]);
}
bool Union(EDGE &edge)
{
    int x=Find_Root(edge.A);
    int y=Find_Root(edge.B);

    if(x!=y) 
	{
        Set[x]=y;
        return true;
    }
    return false;
}

int main()
{
    int N, M, A, B, L;
    while(scanf("%d %d",&N,&M)==2) 
	{

        for(int i=0;i<M;++i)
        {
        	scanf("%d %d %d", &edge[i].A, &edge[i].B, &edge[i].L);
		}
            
        sort(edge, edge + M, cmp);
        Ini(N);

        vector<EDGE> Ans;
        for(int i=0,currentEdge=0;currentEdge!=N-1;++i)
        {
        	if(Union(edge[i]))
			{
                ++currentEdge;
                Ans.push_back(edge[i]);
            }
		}
            
        printf("%d\n",(Ans.end()-1)->L);
        printf("%d\n",Ans.size());
        
		for(int i=0;i<Ans.size();++i)
        {
        	printf("%d %d\n",Ans[i].A,Ans[i].B);
		}
            
    }
}

