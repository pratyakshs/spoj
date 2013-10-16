#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

int main()
{	
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		
		int x, y;
		scanf("%i %i", &x, &y);
		if(x==y)
		{
			if(x%2)
				printf("%i\n", 2*x-1);
			else
				printf("%i\n", 2*x);
		}
		else if(x-y==2)
		{
			if(y%2)
				printf("%i\n", 2*y+1);
			else
				printf("%i\n", 2*y+2);
		}
		else
			printf("No Number\n");
	}
	return 0;
}