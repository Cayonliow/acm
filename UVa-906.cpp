#include<iostream>
#include <cstdio>

using namespace std;

int main() {
    long long int a,b,c,d;
    double eps;
    long double cat,cut;
    while(scanf("%lld %lld",&a,&b)==2) 
	{
        scanf("%lf",&eps);
        cat=(long double)a/b;
        for(d=1;;d++) 
		{
            c=(long long int)(cat*d);
            
			while(a*d>=b*c)
			{
				c++;
			}
                
			cut=(long double)c/d;
            
			if(cut-cat<=eps) 
			{
                printf("%lld %lld\n",c,d);
                break;
            }
        }
    }
    return 0;
}
