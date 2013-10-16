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
		bignum N;
		scanf("%lli", &N);
		if(N%2)
		{
			printf("%lli\n", ((N-1)*(N-1)/4)%N);
		}
		else
			printf("%lli\n", ((N-2)*(N-2)/4)%N);
	}
	return 0;
}