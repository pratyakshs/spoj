#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

int main()
{	
	int g,b;
while(scanf("%i %i", &g, &b)!=EOF)
{
	if(g==-1 && b==-1)
		break;
	if(g==0 && b==0)
		{
			printf("0\n");
			continue;
		}
	if(g>b)
		printf("%i\n", (int)ceil(g/(b+1.0)));
	else if (b>g)
		printf("%i\n", (int)ceil(b/(g+1.0)));
	else
		printf("1\n");
}

	return 0;
}