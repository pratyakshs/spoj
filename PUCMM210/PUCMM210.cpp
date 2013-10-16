#include<stdio.h>
typedef unsigned long long bignum;
bignum table[1000001];

bignum calc(int n)
{
	if(table[n]!=-1)
		return table[n];
	else{
		table[n]=calc(n-1)+(n*n*(n+1)*(n+1)/4);
		return table[n];
	}
}
int main()
{
	for(int i=0; i<1000001; i++)
		table[i]=-1;
	table[0]=0;
	table[1]=1;
	for(int i=1; i<800000; i++)
		calc(i);
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int n;
		scanf("%i", &n);
		printf("%llu\n", calc(n));
	}
}