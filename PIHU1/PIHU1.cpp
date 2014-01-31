#include<bits/stdc++.h>
using namespace std;
typedef long long bignum;
int main(){
	int t, n;
	bignum p, sum, goal;
	bool flag;
	scanf("%i", &t);
	while(t--){
		scanf("%i", &n);
		bignum arr[n];
		for(int i=0; i<n; i++) scanf("%lli", &arr[i]);
		scanf("%lli", &p);
		sort(arr, arr+n);
		flag=false;
		for(int i=0; i<n; i++){
			goal=p-arr[i];
			for(int j=0, k=n-1; j<k;){
				sum=arr[j]+arr[k];
				if(j==i) j++;
				else if(k==i) k--;
				else if(sum==goal && i!=j && i!=k){
					flag=true;
					break;
				}
				else if(sum<goal)
					j++;
				else if(sum>goal)
					k--;
			}
			if(flag) break;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
