#include<stdio.h>
#include<math.h>
using namespace std;

typedef unsigned long long int bigint;
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		bigint x,y,z;
		scanf("%lli %lli %lli", &x, &y, &z);
		bigint a=x+y, b=7*x+5*y+2*z, c=12*z;
		bigint n=(b+sqrt(b*b-4*a*c))/(2*a);
		bigint d=(y-x)/(n-6);
		bigint A=x-2*d;
		printf("%lli\n", n);
		for(bigint j=0; j<n; j++)
		{
			printf("%lli ", A+j*d);
		}
		printf("\n");
	}
	return 0;
}