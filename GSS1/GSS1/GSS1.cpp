#include<stdio.h>
#include<algorithm>

using namespace std;
int main()
{	
	int N,t;
	scanf("%u", &N);
	int X[N];
	for(int i=0; i<N; i++)
		scanf("%u", &X[i]);
	scanf("%u", &t);
	for(int i=0; i<t; i++)
	{
		int U, L,maxsofar=0, maxlast=0;;
		scanf("%u %u", &L, &U);
		for(int j=L-1; j<U; j++)
		{
			maxlast = max(maxlast+X[j], 0);
			maxsofar = max(maxsofar, maxlast);
		}
		printf("%u\n", maxsofar);
	}
	return 0;
}