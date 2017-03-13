#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <algorithm>  

using namespace std;  
 
struct COOR 
{  
	int x;  
	int y;  
	COOR *next;  
	
}point[1100],x3,x4;  

COOR *hash[1500]; 
 
int insert_hash(COOR &a)  
{  
	COOR *p;  
	p=(COOR*)malloc(sizeof(COOR));  
	*p=a;  
	p->next=hash[((a.x*a.x)+(a.y*a.y))%97+1];  
	hash[((a.x*a.x)+(a.y*a.y))%97+1]=p;  
	return 0;  
}  

int find_ans(COOR &a)  
{  
	int pos=((a.x*a.x)+(a.y*a.y))%97+1;  
	COOR *p=hash[pos];  
	
	while(p!=NULL)  
	{  
		if(p->x==a.x && p->y ==a.y)  
		return 1;  
		p=p->next;  
	}  
	return 0;  
}  

int n;  

int main()  
{  
	while(scanf("%d",&n),n!=0)  
	{  
		int answer=0;  
		memset(hash,0,sizeof(hash));  
		for(int i=0;i<n;i++)  
		{  
			scanf("%d%d",&point[i].x,&point[i].y);  
			insert_hash(point[i]);  
		}  
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)  
			{  
				x3.x=point[i].x+(point[i].y-point[j].y);  
				x3.y=point[i].y-(point[i].x-point[j].x);  
				x4.x=point[j].x+(point[i].y-point[j].y);  
				x4.y=point[j].y-(point[i].x-point[j].x);  
			
				if(find_ans(x3) && find_ans(x4))
				{
					answer++; 
				} 
 
				x3.x=point[i].x-(point[i].y-point[j].y);  
				x3.y=point[i].y+(point[i].x-point[j].x);  
				x4.x=point[j].x-(point[i].y-point[j].y);  
				x4.y=point[j].y+(point[i].x-point[j].x);  
				
				if(find_ans(x3) && find_ans(x4))
				{
					answer++;
				}
  
			} 
		}
 
		printf("%d\n",answer/4);  
	}  
	
return 0;  
}  
