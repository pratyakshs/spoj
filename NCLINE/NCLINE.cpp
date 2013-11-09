#include<stdio.h>
typedef unsigned long long bignum;
int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		bignum n, x, left=1;
		bool flag;
		scanf("%llu", &n);
		int arr[n];
		for(int i=0; i<n; i++)
			scanf("%i", &arr[i]);
		for(int i=0; i<n; i++){
			if(arr[i]>left){
				printf("No\n");
				goto here;
			}
			left=(left-arr[i])<<1;
			if(i==n-1 && left){
				printf("No\n");
				goto here;
			}
		}
		printf("Yes\n");
here:;
	}
	return 0;
}



