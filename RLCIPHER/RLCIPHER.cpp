#include<bits/stdc++.h>
int main(){
	int t;
	scanf("%i", &t);
	int arr[]={-4, -3, -2, -4, -4, -3, -4, -4};
	while(t--){
		int n, x;
		scanf("%i", &n);
		while(n--){
			scanf("%i", &x);
			if(x>=6)
				printf("-4 ");
			if(x<0)
				printf("%i ", x);
			else 
				printf("%i ", arr[x]);
		}
		printf("\n");
	}
	return 0;
}
