#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

int main()
{	
	while(1==1)
	{
		bigint a1, a2, a3;
		scanf("%lli %lli %lli", &a1, &a2, &a3);
		if(a1==0 && a2==0 && a3==0)
			break;
		if(a2-a1==a3-a2)
		{
			printf("AP %lli\n", a3+a3-a2);
		}
		else
			printf("GP %lli\n", a3*a2/a1);
	}
	return 0;
}