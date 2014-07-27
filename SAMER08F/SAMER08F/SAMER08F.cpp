#include<stdio.h>
int main(){
	unsigned long long n;
	while(scanf("%llu", &n)!=EOF){
		if(n==0)
			return 0;
		printf("%llu\n", n*(n+1)*(2*n+1)/6);
	}
}
