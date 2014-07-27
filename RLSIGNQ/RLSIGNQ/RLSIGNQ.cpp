#include<bits/stdc++.h>
int main(){
	int t, n, k, x;
	scanf("%i", &t);
	while(t--){
		scanf("%i %i", &n, &k);
		int sum=0;
		while(n--){
			scanf("%i", &x);
			sum+=x;
		}
		if(sum%k==0)
			printf("%i\n", sum/k);
		else
			printf("%i\n", sum/k+1);
	}
	return 0;
}

	
