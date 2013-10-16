#include<stdio.h>
typedef unsigned long long bignum;

bignum table[1000001];
bignum sumdiv(bignum num)
{
	bignum sum=0, step=1;
	if(num%2) step=2;
	for(bignum i=1; i*i<=num; i+=step)
		sum += (num%i)? 0 : ((i*i==num)? i : i+num/i);
	return sum-num;
}

bignum afs(int n){
	if(table[n]!=-1)
		return table[n];
	else{
		table[n]=afs(n-1)+sumdiv(n);
		return table[n];
	}
}

int main()
{
	for(int i=0; i<1000001; i++)
		table[i]=-1;
	table[0]=0;
	table[1]=0;
	for(int i=1; i<800000; i++)
		afs(i);
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int n;
		scanf("%i", &n);
		printf("%llu\n", afs(n));
	}
}