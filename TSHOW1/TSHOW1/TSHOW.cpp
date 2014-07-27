#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		unsigned long long x;
		scanf("%llu", &x);
		int j=0;
		while((2*((2<<j)-1)) <=x-1)
		{
			j++;
		};
		unsigned long long y=x-(2*((1<<j)-1));
		printf("j=%i\n", j);
		printf("y=%llu\n", y);
		for(int k=j+1; k>0; k--)
		{
			printf("%i", y&(1ULL<<k));
			/*if(y&(1>>k))
				printf("6");
			else
				printf("5");*/
		}
		printf("\n");
		//printf("%i\n", j);

	}
}