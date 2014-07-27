#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int xa, ya, xb, yb, xc, yc, r, R;
		scanf("%i %i %i %i %i %i %i %i", &xa, &ya, &xb, &yb, &xc, &yc, &r, &R);
		double m=double(ya-yb)/(xa-xb);
		double d=((xc-xa)*m+ya-yc)/sqrt(1+m*m);
		//printf("%f\n", d);
		if((d>0?d:(-d))>=r+R)
		{
			printf("%.2f\n", sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)));
		}
		else
		{
			double D=sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc));
			double a=r*D/(R+r), b=R*D/(R+r);
			double d1=sqrt(a*a-r*r)+sqrt(b*b-R*R);

			double d3=sqrt((xc-xb)*(xc-xb)+(yc-yb)*(yc-yb)-(R+r)*(R+r));\
			double dab2=((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
			double dbc2=(xb-xc)*(xb-xc)+(yb-yc)*(yb-yc);
			double d2=(R+r)*(acos((D*D+dbc2-dab2)/(2*D*sqrt(dbc2)))-acos((R+r)/D)-acos((R+r)/sqrt(dbc2)));
			
			printf("%.2f\n", d1+d2+d3);
		}
	}
	return 0;
}