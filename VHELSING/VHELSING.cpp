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
		int r;
		scanf("%i", &r);
		printf("%.4f\n", 8*(2-sqrt(2))*r*r*r);
	}
	return 0;
}