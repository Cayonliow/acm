#include<iostream>
#include<cstdio>
int p[100000];
int record[100000];

void MakeSet(int x)
{
	p[x]=x;
	record[x]=0;
}

int FindSet(int x)
{
	if(x!=p[x])
        p[x]=FindSet(p[x]);
    return p[x];
}

void Link(int x,int y)
{	
	p[y]=x;
}

void Union(int x,int y)
{
    Link(FindSet(x),FindSet(y));
}

int main()
{
    int n,m,i,j,h,a,b,mark;
    h=0;
    while(scanf("%d %d",&n,&m)==2)
    {
    	mark=0;
        if(n==0&&m==0)
            return 0;
        
        
        for(i=1;i<=n;i++)
        {
           MakeSet(i);
        }
		 
		 for(i=0;i<m;i++)
		 {
		 	scanf("%d %d",&a,&b);
		 	Union(a,b);
		 }
		 
        for(i=1;i<=n;i++)
        {
            record[FindSet(i)]++;
        }
    
        for(i=1;i<=n;i++)
        {
            if(record[i]!=0)
            {
                mark++;
            }
       
        }
        h++;
    printf("Case %d: %d\n",h,mark);
	mark=0;
    }
 return 0;
}
/*
10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10




10 4
2 3
4 5
4 8
5 8
*/
