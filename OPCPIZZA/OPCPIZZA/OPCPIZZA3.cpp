#include<set>
#include<stdio.h>
#include<vector>
#include<map>
#include<set>

using namespace std;
typedef long long bigint;
int main(){
	bigint t;
	scanf("%lli", &t);
	for(bigint i=0; i<t; i++){
		bigint n, m,count=0;
		set<bigint> values; vector<bigint> v;
		scanf("%lli %lli", &n, &m);
		for(bigint j=0; j<n; j++){
			bigint x;
			scanf("%lli", &x);
			if(x+x!=m)
				values.insert(x), v.push_back(x);
		}
		for(int j=0; j<n; j++)
		{
			set<bigint>::iterator it2=values.find(m-v[j]);
			if(it2!=values.end())
			{
			//	values.erase(it);
			//	values.erase(it2);
				count++;
			}
		}
	
		printf("%lli\n", count/2);

	}
}