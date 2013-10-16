
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long int bigint;

bigint table[100000];
bigint compute(bigint x)
{
	if(x==0)
		return 0;
	else if(x>99999)
		return max(x, compute(bigint(x/2))+compute(bigint(x/3))+compute(bigint(x/4)));

	else if(table[x]!=-1)
		return table[x];
	else
	{
		table[x]=max(x, compute(bigint(x/2))+compute(bigint(x/3))+compute(bigint(x/4)));
		return table[x];
	}
}
int main() {
	bigint n;

	for(bigint i=0; i<100000; i++)
	{table[i]=-1;}

	while(cin>>n)
	printf("%lli\n", compute(n));


	return 0;
}
