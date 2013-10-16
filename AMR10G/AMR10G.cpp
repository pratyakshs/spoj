#include<stdio.h>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int n, k;
		scanf("%i %i", &n, &k);
		vector<int> v(n);
		for(int j=0; j<n; j++){
			scanf("%i", &v[j]);
		}
		sort(v.begin(), v.end());
		int m=INT_MAX;
		for(int j=0; j+k-1<v.size(); j++){
			int x=v[j+k-1]-v[j];
			if(x<m)
				m=x;
		}
		printf("%i\n", m);
	}

}