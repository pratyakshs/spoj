#include<stdio.h>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
	int n;
	while(scanf("%i", &n)!=EOF){
		vector<long long> arr(n);
		for(int i=0; i<n; i++)
			scanf("%lli", &arr[i]);
		vector<vector<long long> > ans(n, vector<long long>(n, -1)), ps(n, vector<long long>(n, -1));
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
		//		ps[j+x][j]=(ps[j+x-1][j]+arr[j+x])%100;
			}
		}
		printf("%lli\n", ans[n-1][0]);
/*			for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				printf("%lli ", ans[i][j]);
			printf("\n");
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				printf("%lli ", ps[i][j]);
			printf("\n");
		}*/
	}	
	return 0;
}
