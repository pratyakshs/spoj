#include<stdio.h>
#include<math.h>
using namespace std;
typedef unsigned long long bignum;
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		bignum n;
		scanf("%llu", &n);
		bignum s=sqrt(n);
		if(s*s==n || (s-1)*(s-1)==n || (s+1)*(s+1)==n)
			printf("Case %i: Yes\n", i+1);
		else
			printf("Case %i: No\n", i+1);
	}
}
