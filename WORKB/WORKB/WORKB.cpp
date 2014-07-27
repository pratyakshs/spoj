#include<stdio.h>
typedef unsigned long long bignum;
int main(){
	int t;		
	scanf("%i", &t);
	for(int j=1; j<=t; j++){
		bignum n, a, b;
		scanf("%llu %llu %llu", &n, &a, &b);
		bignum prev=0, curr=0;
		char where='b';
		bignum total=0;
		scanf("%llu", &prev);
		total+=a;
		where='s';
		for(bignum i=1; i<n; i++){
			scanf("%llu", &curr);
			if((curr-prev-1)*b > 2*a){
				total+=2*a;
			}
			else{
				total+=(curr-prev-1)*b;
			}
			prev=curr;
		}
		total+=a;
		total+=b*n;
		printf("Case #%i: %llu\n", j, total);

	}
	return 0;
}






