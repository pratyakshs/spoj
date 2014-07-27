#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int n;
		scanf("%i", &n);
		vector<int> v(n);
		for(int j=0; j<n; j++)
			scanf("%i", &v[j]);
		for(int j=0, k=n-1; j<(n-1)/2; j++, k--)
		{
			v[j+1]-=v[j];
			v[j]=0;
			v[k-1]-=v[k];
			v[k]=0;
		}
		if(n%2)
		{
			if(v[(n-1)/2])
				printf("NO\n");
			else
				printf("YES\n");
		}
		else
		{
			if(v[n/2]==v[(n/2)-1])
				printf("YES\n");
			else
				printf("NO\n");
		}


		

	}
}