#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;
	
int a[100], b[100];
int singleline[100];
int ans[100][100];
int count;

void multiply(int length, int b)
{
	
	for(int i=0;i<length;++i)
	{
		singleline[i]=a[i]*b;
	}
	
	for(int i=0;i<length-1;++i)
	{
		singleline[i+1]+=singleline[i]/10;
		singleline[i]%=10; 
	}
	
	for(int i=0;i<length;++i)
	{
		ans[count][count+i]=singleline[i];
	}
	count++; 
}

void final_add(int length) 
{
	for(int j=0;j<count-1+length;++j)
	{	
		for(int i=0;i<count;++i)
		{

			ans[count][j]=ans[count][j]+ans[i][j];
		} 
	
	} 
		for(int i=0;i<count-1+length;++i)
	{
		ans[count][i+1]+=ans[count][i]/10;
		ans[count][i]%=10; 
	}
}


 
int main()
{
	
	char tmp_a[100];
	char tmp_b[100];
	memset(tmp_a,sizeof(tmp_a),' ');
	memset(tmp_b,sizeof(tmp_b),' ');
	while(scanf("%s %s",tmp_a,tmp_b)==2)
	{
		count=0;
		memset(singleline,sizeof(singleline),0);
		memset(ans,sizeof(ans),0);
		memset(a,sizeof(a),0);
		memset(b,sizeof(b),0);
		int a_len = strlen(tmp_a);
		int b_len = strlen(tmp_b);
		
		for(int i=0;i<100;++i)
		{
			a[i]=0;
			b[i]=0; 
			for(int j=0;j<100;++j)
				ans[i][j]=0;
		} 

		for(int i=0;i<a_len;++i)
			a[i]= tmp_a[a_len-i-1]-'0';
		
		for(int i=0;i<b_len;++i)
		{
			b[i]= tmp_b[b_len-i-1]-'0';
			multiply(a_len,b[i]);
		}
			
		int space=(a_len>b_len?a_len:b_len);

		
		final_add(a_len);
		int ll=a_len+count-1-1; 
		
		if(ans[count][a_len+count-1]!=0)
			ll++; 
		
		for(int i=0;i<=ll-a_len;++i){
			printf(" ");
		}
		for(int i=a_len-1;i>=0;--i){
			printf("%d",a[i]);
		}
		printf("\n");
		
		for(int i=0;i<=ll-b_len;++i){
			printf(" ");
		}	
		for(int i=b_len-1;i>=0;--i){
			printf("%d",b[i]);
		}
		printf("\n");
		
		int yy=0;
		for(int j=0;j<count;++j)
		{
			if(b[j]==0)
			{
				yy++;
			}
		}
		if(b_len>1&&(a_len>1)&&(yy!=b_len-1))
		{		
			for(int i=0;i<=ll-space;++i)
				printf(" ");

			for(int i=space-1;i>=0;--i)
				printf("-");

			printf("\n");
					
			int y=0;
			for(int j=0;j<count;++j)
			{
				if(b[j]==0)
				{
					y++;
				}
				else{
					
					int q=0;
					while(ans[j][q]==0)
					{
						q++;
					}
					q=q-1;	
					int h=a_len+count-1; 
					while(ans[j][h]==0)
					{
						h--;
					}
					
					h=h-1;
					for(int i=0;i<ll-q-h;i++)printf(" "); 
					//printf("##=%d ###%d\n",q,h);	
						
						
						/*//printf("rrrr=%d\n",a_len+j+1);
						for(int i=0;i<count-1-j-1;++i)
							printf(" "); 
*/
						for(int i=a_len-1+j;i>=0+j;--i)
							printf("%d",ans[j][i]);
						
							printf("\n");
				}
				
			} 
		}		

		for(int i=ll;i>=0;--i)
			printf("-");
		printf("\n");
		
		if((a_len==1&&a[0]==0)||(b_len==1&&b[0]==0))
		{
			for(int i=0;i<ll;i++)
				printf(" "); 
			printf("0\n");
			
		}	
		else
		{
			for(int i=ll;i>=0;--i)
				printf("%d",ans[count][i]);
			printf("\n");
		}			
	printf("\n");
	}
				
} 
