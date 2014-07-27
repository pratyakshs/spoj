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

int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		int a, b;
		scanf("%i %i", &a, &b);
		int g=gcd(a,b);
		int numDiv=0;
		for(int j=1; j*j<=g; j++)
		{
			if(j*j==g)
				numDiv++;
			else if(g%j==0)
				numDiv+=2;
		}
		printf("%i\n", numDiv);
	}
}