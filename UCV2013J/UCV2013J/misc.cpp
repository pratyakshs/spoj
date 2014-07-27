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

int main(){
	int n;
	scanf("%i", &n);
	printf("%i\n", p(n));
}