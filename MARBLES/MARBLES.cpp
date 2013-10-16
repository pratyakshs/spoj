#include<stdio.h>

typedef unsigned long long bignum;

int main()
{	
	int t;
	scanf("%i", &t);
	for(int k=0; k<t; k++)
	{
		bignum n, k, num=1, den=1, i, j, ans=1;
		scanf("%lli %lli", &n, &k);
		if(k>n)
		{
			printf("0\n");
			continue;
		}
		for(i=n-1, j=1; i>=n-k && j<=k-1; i--, j++)
		{
			ans=ans*i/j;
		}
		if(i==n-k)
		{
			for(; j<=k-1; j++)
				ans=ans/j;
		}
		if(j==k-1)
		{
			for(; i>=n-k; i--)
				ans*=i;
		}
		printf("%lli\n", ans);
	}
	return 0;
}