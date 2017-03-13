#include<iostream>
#include<cstdio>

int p[200010];
int r[200010];
int map[200010];
long long s[200010];

int find(int x) 
{
    return p[x]==x?x:p[x]=find(p[x]);
}

void joint(int x,int y,int i,int j) 
{
    if(x==y)
    {
    	return;
	}    
    
	s[x]+=s[y];
    r[x]+=r[y];
    s[y]=0;
    r[y]=0;
    p[y]=x;

}

int main() 
{
    int n,m,q,t,x,y,j,h,g;
    
    while(scanf("%d %d",&n,&m)==2) 
	{

    	for(int i=0;i<=n+m;i++) 
		{
        	map[i]=i;
			p[i]=i;
			s[i]=0;
			r[i]=1;  
    	}

        for(int i=0;i<=n;i++)
        {
        	s[i]=i;
		}
            
        for(int i=0;i<m;i++)
		{
            scanf("%d %d",&q,&h);
            
			if(q==3) 
			{
                t=find(map[h]);
                
				printf("%d %lld\n",r[t],s[t]);
            } 
			
			else if(q==2) 
			{
                scanf("%d",&g);
                x=find(map[h]);
                y=find(map[g]);
                if(x!=y)
				{
                    s[x]-=h;
					r[x]--;
                    map[h]=++n;
                    s[map[h]]=h;
                    r[map[h]]=1;
                    
					joint(find(map[h]),find(map[g]),h,g);
                }
            } 
			
			else 
			{
                scanf("%d",&g);
                
				joint(find(map[h]),find(map[g]),h,g);
            }
        }
    }
    return 0;
}
