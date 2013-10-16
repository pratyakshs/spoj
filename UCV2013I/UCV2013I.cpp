#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#define pi 3.141592653589793238462643383279502884197169399375105820974944
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

int main()
{	
	int r,n ;
	while(scanf("%i %i", &r, &n))
	{
		if(r==0 && n==0)
			break;
		printf("%.2f\n", r/sin(pi/(2*n)));
	}
	return 0;
}