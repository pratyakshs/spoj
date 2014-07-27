#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long bigint;

int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int n;
		scanf("%i", &n);
		vector<int> maxNumber(n,0);
		for(int j=0; j<n; j++)
			scanf("%i", &maxNumber[j]);
		sort(maxNumber.begin(), maxNumber.end());
		unsigned long long count=1;
		for(int j=0; j<n; j++)
		{
			count=(count*(maxNumber[j]-j))%1000000007;
		}
		printf("%lli\n", count);
	}
	printf("KILL BATMAN\n");
	return 0;
}