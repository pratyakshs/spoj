#include<stdio.h>
typedef unsigned long long bigint;

bigint f(bigint n, bigint diff[], bigint curr, bigint index, bigint sum, bigint x)
{
	if(index==n)
	{
		return curr;
	}
	else
	{
		for(bigint i=1; i<=diff[index]; i++)
		{
			curr=((curr*(x-i+1))/i);
			if(curr>(1ULL<<63))
			{
				curr%=1000000007;
			}
			printf("Pass:%llu, val=%llu\n", x, curr);
		}
		f(n, diff, curr, index+1, sum, x-diff[index]);
	}

}
int main()
{
	bigint n;
	scanf("%llu", &n);
	bigint initial[n], final[n], diff[n];
	bigint sum=0;
	while(n>0)
	{
		for(bigint i=0; i<n; i++)
			scanf("%llu", &initial[i]);
		for(bigint i=0; i<n; i++)
			scanf("%llu", &final[i]);
		for(bigint i=0; i<n; i++)
		{
			diff[i]=final[i]-initial[i];
			sum+=diff[i];
		}
		printf("%llu\n", f(n, diff, 1, 0, sum, sum));
		scanf("%llu", &n);
	}
}