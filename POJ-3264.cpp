#include<iostream>
#include<cstdio>
#include<cmath>
#define MAX 50000

using namespace std;

struct Node
{
	int l,r;
	int max,min;
	Node *left,*right;
};

Node tree[MAX*2];
int num[MAX];
int nNodeCnt=0;

int max(int a,int b)
{
	if(a>=b)
	{
		return a;
	}
	
	if(a<b)
	{
		return b;
	}
}

int min(int a,int b)
{
	if(a<=b)
	{
		return a;
	}
	
	if(a>b)
	{
		return b;
	}
}


void build(Node *rt, int l, int r)
{
	rt->l=l;
	rt->r=r;
	
	if(l==r)
	{
		rt->max=num[l];
		rt->min=num[l];
		return;
	}
	
	nNodeCnt++;
	rt->left=tree+nNodeCnt;
	nNodeCnt++;
	rt->right=tree+nNodeCnt;
	
	int m=(l+r)>>1;
	build(rt->left,l,m);
	build(rt->right,m+1,r);
	rt->max=max(rt->left->max,rt->right->max);
	rt->min=min(rt->left->min,rt->right->min);
}

int ans_max;
int ans_min;
void query(Node *rt, int l, int r)
{
	//printf("ov");
	if(rt->l==l&&rt->r==r)
	{
		ans_max=max(ans_max,rt->max);
		ans_min=min(ans_min,rt->min);
		return;
	}
	
	int m=(rt->l+rt->r)>>1;
	if(r<=m)
	{
		//printf("o\n");
		query(rt->left,l,r);
	}
	
	else if(l>m)
	{
		//printf("ho\n");
	 	query(rt->right,l,r);	
	}
	else
	{
		//printf("go\n");
		query(rt->left,l,m);
		//printf("co\n");
		query(rt->right,m+1,r);
	}
}

int main()
{
	int M;
	int numSearch;
	while(scanf("%d",&M)==1)
	{
			scanf("%d",&numSearch);
			
			for(int i=0;i<M;i++)
			{
				scanf("%d",&num[i]);	
			}
			
			build(tree,0,M-1);
			
			for(int i =0;i<numSearch;i++)
			{
				int x,y;
				scanf("%d %d",&x,&y);
				ans_max=0;
				ans_min=9999999;
				//printf("dd");
				query(tree,x-1,y-1);
				printf("%d\n",ans_max-ans_min);
			}
	}	

}
