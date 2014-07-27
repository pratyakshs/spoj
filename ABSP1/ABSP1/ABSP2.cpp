#include<bits/stdc++.h>
int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		int n;
		scanf("%i", &n);
		int arr[n];
		for(int i=0; i<n; i++) scanf("%i", &arr[i]);
		long long sums[n];
		sums[n-1]=0;
		for(int i=n-2; i>=0; i--){
			sums[i]=sums[i+1]+arr[i+1];
		}
		long long ans=0;
		for(int i=0; i<n; i++){
			ans=ans+sums[i]-((n-i-1)*arr[i]);
		}
		printf("%lli\n", ans);
	}
	return 0;
}
