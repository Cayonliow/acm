#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>


using namespace std;

int p[110];
double answer;

struct COOR
{
	double x,y;
}coor[110];

struct EDGE
{
	int a,b;
	double l;
}edge[110*110];


bool cmp(EDGE A,EDGE B)
{
	return A.l<B.l;	
}

void ini()
{
	for(int i=0;i<110;i++)
	{
		p[i]=i;
	}
	answer=0;
}

int Find(int x)
{
	return (p[x]==x)?x:(p[x]=Find(p[x]));
}

bool Union(EDGE A)
{
	if(Find(A.a)!=Find(A.b))
	{
		p[Find(A.a)]=Find(A.b);
		answer+=A.l;
		return true;
	}
	
	return false;
}

double count_dis(int a,int b,int c,int d)
{
	return sqrt(pow(a-c,2)+ pow(b-d,2));
}

int main()
{
	int Case;
	int number;
	int dis[110][110]={0};
		
	scanf("%d",&Case);
	
		for(int q=0;q<Case;q++)
		{
			scanf("%d",&number);
			
			for(int i=0;i<number;i++)
			{
				scanf("%lf%lf",&coor[i].x,&coor[i].y);
			}
			
			int g=0;
			for(int i=0;i<number;i++)
			{
				for(int j=i+1;j<number;j++)
				{ 
					edge[g].a=i;
					edge[g].b=j;
					edge[g].l=count_dis(coor[i].x,coor[i].y,coor[j].x,coor[j].y);
					//printf("gggg=%f\n",edge[g].l);
					g++;
				}
			}
			
			sort(edge,edge+g,cmp);
			ini();
			
			for(int i=0,sum=0;sum!=number-1;i++)
			{
				if(Union(edge[i]))
				{
					//printf("answer");
					
					sum++;
				}
			}
			
			printf("%.2f\n",answer);
			if (q<Case-1) putchar('\n');
			
		}	
		
	
}
