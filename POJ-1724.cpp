#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 99999999

struct Type {
    vector<int> D;    // next point index
    vector<int> L;    // length
    vector<int> T;    // toll
}BIG[101];

int Distance[101][10001]; //Dis[i][j] ????1??i??j??????
int k, n, r ,s, d, l, t;
bool IN[101] = {0};
queue<int> qq;
int Short ;

void spfa()
{
	while(!qq.empty())
	{
        int current=qq.front();
        IN[current]=false;
        qq.pop();

        for(int i=0;i<BIG[current].D.size();i++)
		{
            int next=(BIG[current].D)[i];
            int n1=BIG[current].L[i];
            int n2=BIG[current].T[i];
            for(int j=0;j+n2<=k;j++) 
			{
                if(Distance[current][j]+n1<Distance[next][j+n2]) 
				{
                    Distance[next][j+n2]=Distance[current][j]+n1;
                    if(!IN[next]) 
					{
                        qq.push(next);
                        IN[next]=true;
                    }
                }
            }
        }
    }
}

int main()
{
    
    scanf("%d %d %d",&k,&n,&r);
    
    for (int i=1;i<=n;i++)
    {
    	for(int j=0;j<=k;j++)
    	{
    		Distance[i][j]=0x3f3f3f3f;
		}
            
	}
        
    for(int i=0;i<=k;i++)
    {
    	Distance[1][i]=0;
	}
    
    for(int i=0;i<r;i++)
	{
        scanf("%d %d %d %d",&s,&d,&l,&t);
        BIG[s].D.push_back(d);
        BIG[s].L.push_back(l);
        BIG[s].T.push_back(t);
    }


	qq.push(1);
	IN[1] = true;

    spfa();
    
	Short=0x3f3f3f3f;
    for(int i=0;i<=k;i++)
    {
    	if(Distance[n][i]<Short)
    	{
    		Short=Distance[n][i];
		} 
	}
        
    if(Short==0x3f3f3f3f) 
	{
		puts("-1");
	}
    else
    {
    	printf("%d\n",Short);
	}
	
}
