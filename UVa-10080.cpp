#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std; 

vector<int> list[110];
int dist;
bool used[110];
int n,m,s,v;
int llink[110],rlink[110];

struct GOPHERS
{
	double x,y;
	
}gophers[110];

struct HOLE
{
	double x,y;
	
}hole[110];

void cal_dist()
{
	for(int i=1;i<=n;i++)
	{
		
		list[i].clear();
		for(int j=1;j<=m;j++)
		{
			float walk=sqrt(pow(gophers[i].x-hole[j].x,2)+pow(gophers[i].y-hole[j].y,2));
		
			if(walk<=dist)
			{
				list[i].push_back(j);
			}
		}
	}
}

bool DFS(int now)
{
	for (int i=0;i<list[now].size();i++)
	{
		int next=list[now][i];
		if(!used[next])
		{
			used[next]=true;
			
			if(!rlink[next] || DFS(rlink[next]))
			{
				rlink[next]=now;
				llink[now]=next;
				return true;
			}
		}
	}
	return false;
}

int bipartite(int L){
	int i,ret=0;
	memset(llink,0,sizeof(llink));
	memset(rlink,0,sizeof(rlink));
	for(int i=1;i<=L;++i){
		memset(used,false,sizeof(used));
		if(DFS(i))
			++ret;
	}
	return ret;
}

int main()
{	
	while(scanf("%d %d %d %d",&n,&m,&s,&v)==4)
	{
		dist=s*v;
		
		for(int i=1;i<=n;i++)
		{
			scanf("%lf %lf",&gophers[i].x, &gophers[i].y);
		}
		
		for(int i=1;i<=m;i++)
		{
			scanf("%lf %lf",&hole[i].x, &hole[i].y); 
		}
	
		cal_dist();
		
		printf("%d\n",n-bipartite(n));

	}
}
