#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

#define CLR(a) memset(a,0,sizeof(a))
#define MX 110

vector<int>adj[MX];
int time, dis[MX], low[MX], parent[MX];
bool isArti[MX], vis[MX];

void find_A_P(int u, int root)
{
    low[u] = dis[u] = ++time;
    vis[u]=true;
    int children=0;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(!vis[v])
        {
            children++;
            parent[v]=u;
            find_A_P(v, root);
            low[u]=min(low[u], low[v]);

            if(u==root && children>1)
			{      
            	isArti[u]=true;
			}
			
			else if(u!=root && low[v]>=dis[u])
			{
				isArti[u]=true;
			}
        }
        
        else if(parent[u]!=v)
        {
			low[u]=min(low[u], dis[v]);
		} 
            
    }
    
return;

}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, kk=1;
    string s, s2;
    while(cin>>n && n)
    {
        int cnt=0;
        map<string, int>mp;
        map<int, string>mp2;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            mp[s]=cnt;
            mp2[cnt]=s;
            cnt++;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>s>>s2;
            adj[mp[s]].push_back(mp[s2]);
            adj[mp[s2]].push_back(mp[s]);
        }
        
		time=0;
        vector<string>v;
        cnt=0;
        
        for(int i=0;i<n;i++)
        {
			if(!vis[i]) find_A_P(i,i);
		} 
            

        for(int i=0;i<n;i++)
        {
			if(isArti[i])
			{	
				v.push_back(mp2[i]);
			}
 
		}
		 
            
        if(kk>1)
		{
			cout<<"\n";
		} 
        cout<<"City map #"<<kk++<<": ";
        cout<<v.size()<<" camera(s) found\n";

        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++)
        {
			cout<<v[i]<<"\n";
		} 
            


        for(int i=0;i<n;i++)
		{
			adj[i].clear();
		}
		 
        CLR(vis);
        CLR(parent);
        mp.clear();
        mp2.clear();
        CLR(isArti);
    }
return 0;
}
