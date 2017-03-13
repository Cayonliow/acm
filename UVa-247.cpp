#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<string> name;
vector<string>::iterator it;

bool call[50][50];
int cir[50];

int getIndex(string p)
{
  	it=find(name.begin(),name.end(),p);   
  
  	if(it<name.end())
  	{
  		return it-name.begin();
  	}
  
  	else if(it == name.end())
  	{  
    	name.push_back(p);             
    	return name.size()-1;   
  	} 
}

int main()
{
  	string x,y;
  	int n,m,a,b;
  	int num_case=1;
  	while (scanf("%d %d",&n ,&m)==2&&n!=0&&m!=0)
  	{
  		memset(call,0,sizeof(call));
		memset(cir,-1,sizeof(cir));
    	name.clear();
    
    	for(int j=0;j<m;j++)
		{
			cin>>x>>y; 
			a=getIndex(x);
			b=getIndex(y);
			call[a][b]=1;       
   		}
	
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if (call[i][k]&&call[k][j])
					{
						call[i][j]=1;
					} 
				}
			}
		}
		
		int num=1;
		for(int i=0;i<n;i++)
		{
			if(cir[i]==-1) 
			{
				cir[i]=num;
				for(int j=i+1;j<n;j++)
				{
					if((call[i][j]==1)&&(call[j][i]==1))
					{
						cir[j]=num;
					} 
				}
				
			num++;
			}
		}
		
    	if (num_case>1)
		{
			cout << endl;
		}
		
    	printf("Calling circles for data set %d:\n",num_case);
		//cout << "Calling circles for data set "<<num_case<<":"<<endl; 
	
		for(int i=1;i<num;i++)
		{
			bool first=true;
		
			for(int j=0;j<n;j++)
			{
				if (cir[j]==i) 
				{
					if (first) 
					{
						cout << name[j];
						first=false;
					}
					
					else
					{
						cout<<", "<<name[j];
					}
				}
			}
		
			cout << endl;
		}
    
		num_case++;
  	}         
}
