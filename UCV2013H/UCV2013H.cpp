#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

int main()
{	
	int N,M;
	while(scanf("%i %i", &N,&M))
	{
		if(N==0 && M==0)
			break;

		char matrix[N][M];
		for(int i=0; i<N, i++)
		{
			for(int j=0; j<M; j++)
			{
				scanf("%c", &matrix[i][j]);
			}
		}

		
	}

	return 0;
}