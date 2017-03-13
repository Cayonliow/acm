#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
                                                            
	string TEST1="START";
	string TEST2="END";
	string TEST3="ENDOFINPUT";
	char s2[50]={' '};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	char s3[200]={' '} ;
	char s4[3];
	char s5[200]={' '} ;

	while(gets(s2))
	{
		if(strcmp(s2,"ENDOFINPUT")==0)
			return 0;
			
		while(gets(s3)&&gets(s4))
		{
		
			if(TEST1.compare(s2)==0&&TEST2.compare(s4)==0)
			{
				strcpy(s5,s3);
				for(int i=0;i<100;i++)
				{
					if(s3[i]>='F'&&s3[i]<='Z')
					{
						s5[i]=s3[i]-5;
					}
					if(s3[i]>='A'&&s3[i]<='E')
					{
						s5[i]=s3[i]+21;
					}
			
					
					/*
					if(s3[i]>='V'&&s3[i]<='Z')
					{
						s3[i]=s3[i]-22;
					}*/
				}
	
				puts(s5);
				//printf("\n");
				break;
			}
		}
	}

	return 0;
}
