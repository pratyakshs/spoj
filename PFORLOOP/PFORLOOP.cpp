#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int bigint;
int main()
{	bigint a, count=0;
	vector<bigint> v, counts;
	char c;
	while(scanf("%lli", &a)!=EOF)
	{
		count++;
		v.push_back(a);
		scanf("%c", &c);
		if(c=='\n')
			counts.push_back(count), count=0;
	}
	
	sort(v.begin(), v.end());
	bigint start=v[0];
	for(bigint i=1; i<v.size(); i++)
	{
		if(v[i]-v[i-1]>1)
		{
			printf("for (int i = %lli", start);
				printf("; i <= %lli", v[i-1]);
				printf("; i++) cout << i << \" \";\n");
				start=v[i];
			}
		}
		printf("for (int i = %lli", start);
			printf("; i <= %lli", v[v.size()-1]);
			printf("; i++) cout << i << \" \";");
			return 0;
		}