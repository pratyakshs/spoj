#include<set>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
typedef long long bigint;
int main(){
	bigint t;
	scanf("%lli", &t);
	for(bigint i=0; i<t; i++){
		bigint n, m,count=0;
		map<bigint, bool> values; vector<bigint> v;
		scanf("%lli %lli", &n, &m);
		for(bigint j=0; j<n; j++){
			bigint x;
			scanf("%lli", &x);
			values[x]=false;
			v.push_back(x);
		}
		for(bigint j=0; j<n; j++){
			if(!values[v[j]])
			{
				if(values.find(m-v[j])!=values.end())
				{
					if(!values[m-v[j]] && m-v[j]!=v[j])
					{
						values[m-v[j]]=true;
						values[v[j]]=true;
						//printf("v[j]=%lli\n", v[j]);
						count++;
					}
				}
			}
		}
		printf("%lli\n", count);

	}
}