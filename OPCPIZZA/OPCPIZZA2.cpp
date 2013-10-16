#include<stdio.h>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;
typedef long long bigint;

int main(){
	bigint t;
	scanf("%lli", &t);
	for(bigint i=0; i<t; i++){
		bigint n, m,count=0;
		scanf("%lli %lli", &n, &m);
		bigint *v=new bigint[n], *u=new bigint[n];
		for(bigint j=0; j<n; j++){
			scanf("%lli", &v[j]);
		}
		sort(v, v+n);
		for(int j=0, k=n-1; j<k;){
			int sum=v[j]+v[k];
			if(sum==m){
				count++;
				j++, k--;
			}
			else if(sum>m){
				k--;
			}
			else j++;
		}
		printf("%lli\n", count);

	}
}
