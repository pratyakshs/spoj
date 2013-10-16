#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%i", &t);
	vector<int> v(1000001);
	for(int i=0; i<t; i++)
	{
		for(int j=0; j<1000002; j++)
			v[j]=0;

		int n, count=0;
		scanf("%i", &n);
		vector<int> u;
		for(int j=0; j<n; j++)
		{
			int num;
			scanf("%i", &num);
			v[num]++;
			u.push_back(num);
		}

		sort(u.begin(), u.end());

		for(int j=0; j<n; j++)
		{
			if(u[j]>500000)
				break;

			if(v[u[j]])
			{
				if(v[2*u[j]])
				{	
					count++;
					v[2*u[j]]--;
					v[u[j]]--;
				}
			}
		}
		printf("%i\n", count);
	}
}