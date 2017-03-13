
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    double bottom, height;
    double pi=2*asin(1);
    int Case;
    scanf("%d",&Case);
    for(int uuu=0;uuu<Case;uuu++)
	{
        scanf("%lf %lf",&bottom,&height);
       double circle=0;
    	while (1)
		{
            double side_length=hypot(bottom/2,height);
            double radius=(bottom*height)/(2*side_length+bottom); 
            if(radius<0.000001)
            	break;
			circle = circle+(2*pi*radius);

            double h_tmp=height-2*radius;
            bottom=bottom*(h_tmp/height);
            height=h_tmp;
        }
        printf("%13.6f\n", circle);
        if (uuu<Case-1) printf("\n");
    }
    return 0;
}
