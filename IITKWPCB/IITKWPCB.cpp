#include<stdio.h>

long long gcd(long long a, long long b)
{
	if(b==0)
		return a;
	else
		gcd(b, a%b);
}
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		long long x;
		scanf("%lli", &x);
		for(long long j=x/2; j>0; j--)
		{
			if(gcd(x, j)==1)
			{
				printf("%lli\n", j);
				break;
			}
		}
	}
	
}