#include <bits/stdc++.h>
int main(){
	int n, ii=1;
	while(true){
		scanf("%i", &n);
		if(n==0)
			break;
		int arr[n][n], sum=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%i", &arr[i][j]);
				sum+=arr[i][j];
			}
		}
		int ans=0;
		for(int i=0; i<n; i++){
			int net=0;
			for(int j=0; j<n; j++){
				net+=arr[i][j];
				net-=arr[j][i];
			}
			if(net<0)
				ans-=net;
			else
				ans+=net;
		}
		printf("%i. %i %i\n", ii, sum, ans/2);
		ii++;
	}
	return 0;
}
		
