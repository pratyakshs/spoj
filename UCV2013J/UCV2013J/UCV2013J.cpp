#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

bigint p(bigint N)
{
	bigint ans=0;
	while(N+1> 1<<ans)
	{
		ans++;
	}
	return ans-1;
}
int main()
{	
	bigint N;
	while(scanf("%lli", &N)){
		if(N==0)
			break;
		bigint v, sum=0, n=p(N), b=((1<<n)-1), t=(N)/2;
		//printf("%i %i ", n, b);
		for(bigint i=0; i<t; i++)
		{
			scanf("%lli", &v);
		}
		for(bigint i=t; i<N; i++)
	{
		scanf("%lli", &v);
		sum+=v;
	}
	printf("%lli\n", sum);

	};
	return 0;
}

