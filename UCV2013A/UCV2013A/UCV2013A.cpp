#include<stdio.h>
#include<math.h>
using namespace std;
typedef unsigned long long bignum;

bignum modexp(bignum base, int exponent, bignum modulo)
{
	//computes the remainder when base^exponent is divided by modulo.
	bignum ans=1;
	while(exponent>0)
	{
		if(exponent%2==1)
			ans=(ans*base)%modulo;
		exponent=exponent>>1;
		base=(base*base)%modulo;
	}
	return ans;
}
int main()
{

	bignum n, l;
	scanf("%llu %llu", &n, &l);
	while(n>0 || l>0)
	{
		bignum sum=0;
		for(bignum i=1; i<=l; i++)
		{
			sum+=modexp(n, int(i), 1000000007);
			sum%=1000000007;
		}
		printf("%llu\n", sum);
		scanf("%llu %llu", &n, &l);

	};
}