#include <iostream>  
#include <cstdio>  
#include <cmath>  
#include <climits>  
#include <algorithm>  
#include <vector>  
using namespace std;  
 
struct point
{  
    double x, y;  
    int iniPos;  
    point(double a=0, double b=0, int c=-1)
	{  
        x = a;  
        y = b;  
        iniPos = c;  
    }  
    
	void set(double a, double b)
	{  
        x = a;  
        y = b;  
    }  
    
	double Distance(point t)
	{  
        return sqrt((x-t.x)*(x-t.x) + (y-t.y)*(y-t.y));  
    }  
};  

vector<point> p;  
vector<int> CH;
int top, nodeNum;  
point MC; 
string polyName;  
  
void Input()
{  
    p.clear();  
    CH.clear();  
    double xx, yy;  
    cin >> xx >> yy;  
    MC.set(xx,yy); 
    nodeNum = 0;  
    while(cin >> xx >> yy && (xx || yy))  
    {  
        p.push_back(point(xx, yy, ++nodeNum));  
    }  
    CH.resize(nodeNum+5);  
}  
  
bool cmp(point a, point b)
{  
    if(a.y == b.y)  return a.x < b.x;  
    return a.y < b.y;  
}  

bool turnRight(point px1, point px2, point pp)
{  
    const double eps = 1e-20;  
    if((px2.x - px1.x)*(pp.y - px2.y) - (pp.x - px2.x)*(px2.y - px1.y) <= eps) return true;  
    return false;  
}  

void ComputeCH()
{  
    sort(p.begin(), p.end(), cmp);  
    CH[0] = 0;  
    CH[1] = 1;  
  
    top = 1;  

    for(int i=2; i<nodeNum; i++)
	{  
        while( top && turnRight(p[CH[top-1]], p[CH[top]], p[i]) )  
        {  
           top--;  
        }  
        CH[++top] = i;  
    }  
  
    int len = top;  

    CH[++top] = nodeNum-2;  
    for(int i=nodeNum-3; i>=0; i--)
	{   
        while( top!=len && turnRight(p[CH[top-1]], p[CH[top]], p[i]) )  
        {  
           top--;  
        }  
        CH[++top] = i;  
    }  
}  
 
bool between(point p1, point p2, point pp)
{  
    if( ((pp.x-p1.x)*(p2.x-p1.x)+(pp.y-p1.y)*(p2.y-p1.y)) / fabs(pp.Distance(p1)* p2.Distance(p1)) > 0)  
       return true;  
    return false;  
}  
  
void findAns()
{  
    int ans = INT_MAX;  
 
    for(int i=0; i<top; i++)
	{  

        if(!turnRight(p[CH[i]], p[CH[(i+1)%top]], MC)  
           &&  between(p[CH[i]], p[CH[(i+1)%top]], MC)  
           && between(p[CH[(i+1)%top]], p[CH[i]], MC))
		{  
            ans = min(ans, max(p[CH[i]].iniPos, p[CH[(i+1)%top]].iniPos));  

        }  
    }  
  
    cout << polyName << " " << ans << endl;  
}  

int main()
{  
    while(cin >> polyName && polyName[0]!='#')  
    {  
        Input();  
        ComputeCH(); 
        findAns();
    }  
    return 0;  
}  
