#include<stdio.h>

int main()
{	
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int n;
		scanf("%i", &n);
		printf("%i\n", (n+1)/2);
	}
	return 0;
}