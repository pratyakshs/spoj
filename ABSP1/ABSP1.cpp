#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		int n;
		scanf("%i", &n);
		long long arr[n];
		for(int i=0; i<n; i++) scanf("%lli", &arr[i]);
		long long sums[n], count[n], prev=-1;
		sums[n-1]=0; count[n-1]=0;
		for(int i=n-2; i>=0; i--){
			if(arr[i+1]!=prev){
				prev=arr[i+1];
				sums[i]=sums[i+1]+arr[i+1];
				count[i]=count[i+1]+1;
			}
			else{
				sums[i]=sums[i+1];
				count[i]=count[i+1];
			}
		}
		printf("sums: ");
		for(int i=0; i<n; i++) printf("%lli ", sums[i]);
		printf("\ncounts: ");
		for(int i=0; i<n; i++) printf("%lli ", count[i]);
		long long ans=0; prev=-1;
		for(int i=0; i<n; i++){
			if(arr[i]!=prev){
				ans=ans+sums[i]-(count[i]*arr[i]);
				prev=arr[i];
			}
		}
		printf("%lli\n", ans);
	}
	return 0;
}
