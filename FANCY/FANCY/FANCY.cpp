#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

int f(int n)
{
	if(n==0)
		return 1;
	return 1<< (n-1);

}
int main()
{	
	int t;
	scanf("%i", &t);
	
	for(int i=0; i<t; i++)
	{
		char num[31];
		scanf("%s", num);
		int pos=0,j;
		bignum ans=1;
		for(j=1; num[j]!='\0'; j++)
		{
			if(num[j]!=num[j-1])
			{
				ans*=f(j-pos);
				pos=j;
			}
		}
		ans*=f(j-pos);
		printf("%lli\n", ans);
		
	}
	return 0;
}