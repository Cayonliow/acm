#include<iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<vector>

using namespace std;

struct POINT
{
    int X;
    int Y;
}point[510];

struct EDGE 
{
    int a;
    int b;
    double l;
}edge[510* 510];

int NOFE;
int Set[510];

bool cmp(const EDGE &A, const EDGE &B) 
{
    return A.l < B.l;
}

int Find_Root(int x)
{
    if (x == Set[x])
    {
    	return x;
	}   
    
	return Set[x] = Find_Root(Set[x]);
}

bool Union(const EDGE &edge, vector<double> &LenOfEdge)
{
    int a = Find_Root(edge.a);
    int b = Find_Root(edge.b);
    if (a != b) 
	{
        Set[a] = b;
        LenOfEdge.push_back(edge.l);
        return true;
    }
    
    return false;
}

int main()
{
    int Case;
    int S, P;
    scanf("%d", &Case);
    for(int tt=0;tt<Case;tt++)
	{
        scanf("%d %d", &S, &P);
        for (int i=0;i<P;++i) 
		{
            scanf("%d %d",&point[i].X,&point[i].Y);
            Set[i] = i;
        }
        
		NOFE = 0;
        for (int i=0;i<P;++i) 
		{
            for (int j=i+1;j<P;++j) 
			{
                double L=sqrt(pow(point[i].X-point[j].X,2)+pow(point[i].Y-point[j].Y,2));
                edge[NOFE++]={i,j,L};
            }
        }
        sort(edge,edge+NOFE,cmp);

        vector<double> LenOfEdge;
        
        for (int i=0,nOfEdges=0;nOfEdges!=P-1;++i) 
		{
            if (Union(edge[i],LenOfEdge)) 
			{
				++nOfEdges;
			}
        }

        printf("%.2f\n",LenOfEdge[P-S-1]);
    }
}
