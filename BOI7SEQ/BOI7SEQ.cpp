#include<stdio.h>
using namespace std;
typedef unsigned long long bignum;

int main()
{
	bignum n, curr, prev, sum=0;
	scanf("%llu", &n);
	scanf("%llu", &curr);
	prev=curr;
	for(bignum i=1; i<n; i++)
	{
		scanf("%llu", &curr);
		if(curr>prev)
			sum+=curr;
		else
			sum+=prev;
		prev=curr;
	}
	printf("%llu\n", sum);
}