#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
int no_number;
int sorting_no[1000];
int i,j,tmp;
int count;
while(fscanf(stdin,"%d",&no_number)!=EOF)
{
	//printf("no_number=%d\n",no_number);
	count=0;
	for(i=0;i<no_number;i++)
		fscanf(stdin,"%d",&sorting_no[i]); 
		
	for(i=no_number-1;i>0;i--)
	{
		//printf("i=%d",i);
		for(j=0;j<i;j++)
		{
			if(sorting_no[j]>sorting_no[j+1])
			{
				tmp=sorting_no[j];
				sorting_no[j]=sorting_no[j+1];
				sorting_no[j+1]=tmp;
				count++;
			}
		}
	}
printf("Minimum exchange operations : %d\n",count);
//for(i=0;i<no_number;i++)
//	printf("%d ",sorting_no[i]);
//printf("\n");
}

return 0;

}
 
