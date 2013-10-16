#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int n, m;
		scanf("%i %i", &n, &m);
		int stamps[m];
		for(int j=0; j<m; j++)
			scanf("%i", &stamps[j]);
		sort(stamps, stamps+m);
		printf("Scenario #%i:\n", i+1);
		int j;
		for(j=m-1; j>=0; j--)
		{
			n-=stamps[j];
			if(n<=0)
			{
				printf("%i\n", m-j);
				break;
			}
		}
		if(j<0 && n>0)
			printf("impossible\n");
		printf("\n");
	}
	return 0;

}