#include<stdio.h>

int main(){
	int n,x;
	scanf("%i", &n);
	int ans=0;
	for(int i=1; i<=n; i++){
		scanf("%i", &x);
		ans=ans^x;
	}
	printf("%i\n", ans);
}