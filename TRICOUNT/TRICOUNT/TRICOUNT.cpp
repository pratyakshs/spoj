#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

int main()
{	
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{

		bignum n;
		scanf("%lli", &n);
		bignum pos=n*(n+1)*(n+2)/6, neg;
		if(n%2==0)
		{
			bignum N=n/2;
			neg=N*(N+1)*(4*N-1)/6;
		}
		else
		{
			bignum N=(n-1)/2;
			neg=N*(N+1)*(4*N+5)/6;
		}
		printf("%lli\n", neg+pos);
	}
	return 0;
}