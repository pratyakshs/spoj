#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		int n;
		scanf("%i", &n);
		int sizes[n], c[n];
		for(int i=0; i<n; i++)scanf("%i", &sizes[i]);
		for(int i=0; i<n; i++) scanf("%i", &c[i]);
		sort(sizes, sizes+n);
		int final[n];
		for(int i=n-1; i>=0; i--){
			final[i]=sizes[i-c[i]];
			for(int j=i-c[i]; j<i; j++)
				sizes[j]=sizes[j+1];
		}
		for(int i=0; i<n; i++) printf("%i ", final[i]);
		printf("\n");
	}
	return 0;
}
