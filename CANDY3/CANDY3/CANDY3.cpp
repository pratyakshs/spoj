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
		bignum n,s=0,x;
		scanf("%lli", &n);
		for(bignum i=0; i<n;i++)
		{
			scanf("%lli", &x);
			s+=x;
		}
		
		if(s%n)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}