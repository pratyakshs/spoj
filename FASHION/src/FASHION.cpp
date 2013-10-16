
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;

	for(int j=0; j<t; j++)
	{

		int n;
		scanf("%i", &n);
		vector<int> men, women;
		for(int i=0; i<n; i++)
		{
			int tmp;
			scanf("%i", &tmp);
			men.push_back(tmp);
		}
		for(int i=0; i<n; i++)
		{
			int tmp;
			scanf("%i", &tmp);
			women.push_back(tmp);
		}
		sort(men.begin(), men.end());
		sort(women.begin(), women.end());
		int sum=0;

		for(int i=0; i<n; i++)
		{
			sum+=men[i]*women[i];
		}
		printf("%i\n", sum);

	}

}
