#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int i=1;
	vector<int> v(4);
	while(scanf("%i %i %i %i", &v[0], &v[1], &v[2], &v[3]) != EOF)
	{
		sort(v.begin(), v.end());
		printf("Case %i: %i\n", i,v[3]+v[2]);
		i++;
	} 
	return 0;

}