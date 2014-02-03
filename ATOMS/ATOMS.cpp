#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int t, n, k, m;
	scanf("%lli", &t);
	while(t--){
		scanf("%lli %lli %lli", &n, &k, &m);
		long long int curr=n, time=0, step=n;
		while(double(curr)*double(k)<=double(m)){
			curr*=k;
			time++;
		}
		printf("%lli\n", time);
	}
	return 0;
}






