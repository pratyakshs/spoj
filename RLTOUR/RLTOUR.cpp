#include<bits/stdc++.h>
using namespace std;
int main(){
	int t, n;
	scanf("%i", &t);
	while(t--){
		scanf("%i", &n);
		int sizes[n], c[n], final[n];
		for(int i=0; i<n; i++)scanf("%i", &sizes[i]);
		for(int i=0; i<n; i++) scanf("%i", &c[i]);
		sort(sizes, sizes+n);
		for(int i=n-1; i>=0; i--){
			final[i]=sizes[i-c[i]];
			for(int j=i-c[i]; j<i; j++) sizes[j]=sizes[j+1];
		}
		for(int i=0; i<n; i++) printf("%i ", final[i]);
		printf("\n");
	}
}
