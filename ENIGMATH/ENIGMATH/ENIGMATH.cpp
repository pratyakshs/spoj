#include<stdio.h>
#include<math.h>
using namespace std;

typedef unsigned long long bignum;

bignum gcd(bignum a, bignum b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

bignum lcm(bignum a, bignum b){
	return (a*b)/gcd(a,b);
}

int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		bignum a, b;
		scanf("%llu %llu", &a, &b);
		bignum l=lcm(a,b);
		printf("%llu %llu\n\n", l/a, l/b);
	}
}