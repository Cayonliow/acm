#include<iostream> 
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define WHITE -1

typedef pair<int,int> par;

int vertex, art, dfsCount, dfsRoot, rootChildren;
int dfs_num[10100], dfs_low[10100], art_vertex[10100], dfs_parent[10100];

vector<int> graph[10100];
vector<par> best;

struct ORD
{
	bool operator()(par a, par b)
	{
       if (a.first == b.first)
	   {
       	return (a.second < b.second);
       }
	   else
	   {
	   	return (a.first > b.first);
	   }
	}
};

void clear()
{
	for (int i=0;i<vertex;i++)
	{
		art_vertex[i] = 0;
		graph[i].clear();
		dfs_num[i] = WHITE;
	}
	
	rootChildren=0;
	best.clear();
	dfsCount=0;
}


void artic(int atual)
{
 	dfs_num[atual]=dfs_low[atual]=dfsCount++;
 	
 	for(int i=0;i<graph[atual].size();i++)
	{
   		int novo = graph[atual][i];
   
   		if(dfs_num[novo] == WHITE)
   		{
    		dfs_parent[novo] = atual;
      	
			if (atual == dfsRoot)
			{
      			rootChildren++;
			}
      	
			artic(novo);
		
      		if (dfs_low[novo]>=dfs_num[atual])
      		{
      			art_vertex[atual]++;
			}
      	
      		dfs_low[atual]=min(dfs_low[atual], dfs_low[novo]);
      	}	
   
   		else if (dfs_parent[atual] != novo) 
		{
		   	dfs_low[atual] = min(dfs_num[novo], dfs_low[atual]);
		}
 	}
}

int main()
{
   int u,v;
   while(scanf("%d %d", &vertex, &art) && vertex)
   {
   		clear();
     	while(1)
		{
        	scanf("%d %d", &u, &v);
          	if (u == -1)
			{
			  	break;
			} 
			
          	graph[u].push_back(v);
          	graph[v].push_back(u);
     	}  	
     	
     	for (int i=0;i<vertex;i++)
		{
       		if (dfs_num[i] == WHITE)
			{
       			rootChildren = 0;
       			dfsRoot = i;
        		artic(i);
        		art_vertex[i] = (rootChildren > 1);
       		}
     	}
     
     	for (int i=0;i<vertex;i++)
		{
        	art_vertex[i]++;
     		best.push_back(par(art_vertex[i], i));
     	}
     
     	sort(best.begin(), best.end(), ORD());
     	
		for (int i=0;i<vertex;i++) 
		{
     		printf("%d %d\n", best[i].second, best[i].first);       
     		
			 if (i == art-1) break;
     	}
     	
		printf("\n");
   }
   return 0;
}
