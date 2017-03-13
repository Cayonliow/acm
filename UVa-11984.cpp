#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int number;
	float C,d;
	float C_in_F,final_temp_F,final_temp_C;
	while(scanf("%d",&number)==1)
	{
		for(int i=0;i<number;i++)
		{
			scanf("%f %f",&C,&d);
			C_in_F=(9*C/5)+32;
			final_temp_F=C_in_F+d;
			final_temp_C=(final_temp_F-32)*5/9;
		//printf("C_in_F %.2f,final_temp_F %.2f,final_temp_C %.2f",C_in_F,final_temp_F,final_temp_C);
			printf("Case %d: %.2f\n",i+1,final_temp_C);
		}
	}
	
	return 0;
}
