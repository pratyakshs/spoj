#include<stdio.h>
#include<math.h>

int main()
{	
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		double a, b,c;
		scanf("%lf %lf %lf", &a, &b, &c);



		double y0=0, y1=2500,x1;
for(int i=0; i<100; i++)
  {x1=(y0 + y1)/2;
  	double fc=a*x1+b*sin(x1)-c, fa=a*y0+b*sin(y0)-c;
  
  if ((fc>0 && fa>0) || (fc<0 && fa<0))
  	y0=x1;
  	else
  		y1=x1;
}

		
		for(int i=0; i<100; i++)
		{
				x1=x1-(a*x1+b*sin(x1)-c)/(a+b*cos(x1));
			
		}
		printf("%.6f\n", x1);
	}
	return 0;
}