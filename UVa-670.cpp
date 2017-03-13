#include<iostream>
#include<cstring>
#include<cmath>

int g[205][205], gt[205];
int mx[205], my[205], used[205];
int DFS(int now) 
{
    int x;
    for(int i=0;i<gt[now];i++) 
	{
        x=g[now][i];
        if(!used[x]) 
		{
            used[x]=1;
            if(my[x]==0 || DFS(my[x])) 
			{
                mx[now]=x;
				my[x]=now;
                return true;
            }
        }
    }
    return false;
}
int main() 
{
    int t, n, m;
    int x[105], y[105], X[105], Y[105];
   
    scanf("%d", &t);
    while(t--) 
	{
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
        	scanf("%d %d",&x[i],&y[i]);
		}
            
        for(int i = 1; i <= m; i++)
        {
        	scanf("%d %d", &X[i], &Y[i]);
		}
            
        memset(gt, 0, sizeof(gt));
        memset(mx, 0, sizeof(mx));
        memset(my, 0, sizeof(my));
        
        for(int i=1;i<n;i++) 
		{
            double len=(x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]);
            len = 2*sqrt(len);
            
			for(int j=1;j<=m;j++) 
			{
                double len1=(x[i]-X[j])*(x[i]-X[j])+(y[i]-Y[j])*(y[i]-Y[j]);
                double len2=(x[i+1]-X[j])*(x[i+1]-X[j])+(y[i+1]-Y[j])*(y[i+1]-Y[j]);
                
				len1=sqrt(len1);
				len2=sqrt(len2);
                
				if(len1+len2<=len)
                {
                	g[i][gt[i]++]=j;
				}
                    
            }
        }
        int matched = 0;
        for(int i=1;i<=n;i++) 
		{
            if(!mx[i]) 
			{
                memset(used,0,sizeof(used));
                if(DFS(i))
                {
                	matched++;
				}
                    
            }
        }
        
		printf("%d\n", matched+n);
        for(int i=1;i<=n;i++) 
		{
            if(i!=1)
			{
				putchar(' ');
			} 
			
            printf("%d %d",x[i],y[i]);
            if(mx[i])
            {
            	printf(" %d %d", X[mx[i]], Y[mx[i]]);
			}
                
        }
        
        puts("");
        
        if(t)
		{
			puts("");
		}   
    }
}
