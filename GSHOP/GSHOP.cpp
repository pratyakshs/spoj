#include<bits/stdc++.h>
using namespace std;
int main(){
	int t, n, k;
	scanf("%i", &t);
	while(t--){
		scanf("%i %i", &n, &k);
		int arr[n]; bool flag=true;
		long long int sum=0, mpos=INT_MAX;
		
		for(int i=0; i<n; i++){
			scanf("%i", &arr[i]);
		}
		sort(arr, arr+n);
		for(int i=0; i<n; i++){
			if(arr[i]<0){
				if(k>0){
					arr[i]=-arr[i];
					k--;
				}
			}
			sum+=arr[i];
			if(arr[i]>=0 && arr[i]<mpos){
				mpos=arr[i];
				flag=true;
			}
		}
		if(k%2==0 || k==0)
			printf("%i\n", sum);
		else 
			printf("%i\n", sum-2*mpos);
	}
	return 0;
}
