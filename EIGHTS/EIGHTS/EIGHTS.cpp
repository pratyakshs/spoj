#include<stdio.h>
int main()
{
	int t;
	scanf("%i", &t);
	
	for(int i=0; i<t; i++)
		{
			unsigned long long k;
			scanf("%llu", &k);
			printf("%.0lf\n", (1+2.5*double(k-1))*100+92);
		}

}