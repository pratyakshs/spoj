#include<stdio.h>
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		long long int a, b, c;
		scanf("%lli %lli %lli", &a,&b,&c);
		printf("%lli\n", a*a-2*b);

	}
	return 0;
}