#include<stdio.h>
#include<algorithm>
#define INT_MAX 100000000
using namespace std;

int cost(int n, int energy[][3], int i, int state)
{
	int x0=INT_MAX, x1=INT_MAX, x2=INT_MAX;
	if(i==n-1)
	{
		if(state!=0)
			x0=energy[i][0];
		if(state!=1)
			x0=energy[i][1];
		if(state!=2)
			x0=energy[i][2];
		return min(x0, min(x1, x2));
	}
	else
	{
		if(state!=0)
			x0=energy[i][0]+min(cost(n, energy, i+1, 1), cost(n, energy, i+1, 2));
		if(state!=1)
			x1=energy[i][1]+min(cost(n, energy, i+1, 2), cost(n, energy, i+1, 0));
		if(state!=2)
			x2=energy[i][2]+min(cost(n, energy, i+1, 0), cost(n, energy, i+1, 1));
		return min(x1, min(x0, x2));
	}
}
struct triplet{
	int minval, first, last;
	triplet(int x, int y, int z)
	{
		minval=x;
		first=y;
		last=z;
	}
};

triplet cost(int i, int j, int n, int energy[][3])
{
	divide and conq
}
int main()
{
	int t;
	scanf("%i", &t);	
	for(int i=0; i<t; i++)
	{
		int n;
		scanf("%i", &n);
		int energy[n][3];
		for(int j=0; j<n; j++)
		{
			scanf("%i %i %i", &energy[j][0], &energy[j][1], &energy[j][2]);
		}
		int x0=cost(n, energy, 0, 0);
		int x1=cost(n, energy, 0, 1);
		int x2=cost(n, energy, 0, 2);
		printf("ans:%i\n", min(x1, min(x2, x0)));
	}
}