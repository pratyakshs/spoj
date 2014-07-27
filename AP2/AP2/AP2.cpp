#include<stdio.h>
#include<math.h>

using namespace std;

typedef long long int bigint;

int main()
{
	int t;
	scanf("%i", &t);
	for(int k=0; k<t; k++)
	{
		bigint x, y, z;
		scanf("%lli", &x);
		scanf("%lli", &y);
		scanf("%lli", &z);
		bigint n=2*z/(x+y);
		bigint d=(y-x)/(n-5);
		bigint a=x-2*d;
		printf("%lli\n", n);
		for(bigint i=0; i<n; i++)
			printf("%lli ", a+i*d);
		printf("\n");
	}
	return 0;
}