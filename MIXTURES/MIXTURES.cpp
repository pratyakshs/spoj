#include<stdio.h>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
	int n;
	while(scanf("%i", &n)!=EOF){
		long long arr[n], ans[n][n], ps[n][n];
		for(int i=0; i<n; i++)
			scanf("%lli", &arr[i]);
		for(int i=0; i<n; i++){
			ans[i][i]=0;
			ps[i][i]=arr[i]%100;
		}
		for(int x=1; x<n; x++){
			for(int j=0; j+x<n; j++){
				ps[j+x][j]=(ps[j+x-1][j]+arr[j+x])%100;
				long long int m=LLONG_MAX, temp;
				for(int i=0; i<x; i++){
					temp=ans[j+x-1-i][j]+ans[j+x][j+x-i]+ps[j+x-i-1][j]*ps[j+x][j+x-i];
					if(temp<m)
						m=temp;
				}
				ans[j+x][j]=m;
			}
		}
		printf("%lli\n", ans[n-1][0]);
	}	
	return 0;
}
