#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

bool prime[1000000];

int main()
{	
	for(int i=2; i<1000000; i++)
		prime[i]=true;
	prime[0]=prime[1]=false;
	for(int i=2; i<1000; i++)
		if(prime[i])
			for(bignum j=i*i; j<1000000; j+=i)
				prime[j]=false;
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int a, b, n, count=0, pcount=0;
		scanf("%i %i %i", &a, &b, &n);
		if(n==0)
			if(a==1)
				printf("1\n");
			else 
				printf("0\n");
		else if (n==1)
		{
			for(int j=a; j<=b; j++)
				if(prime[j])
					count++;
			printf("%i\n", count);
		}
		else
		{

		for(int j=a; j<=b ; j++)
		{
			pcount=0;
			
			for(int k=2; k<=j/2 && pcount<=n; k++)
			{
				if(prime[k])
					if(j%k==0)
						pcount++;
			}
			if(pcount==n)
				count++;
		}
		printf("%i\n", count);
	}
}
	

	return 0;
}