#include<bits/stdc++.h>
typedef unsigned long long bignum;
inline bignum sum(int a){	
	int x=log2(a);
	bignum sum=0, prev=0;
	for(; x>=0; x--){
		bignum temp=a/pow(2, x);
//		printf("x=%i sum=%llu prev=%llu curr=%llu\n", x, sum, prev, temp-prev);
		sum+=(temp-prev)*pow(2, x);
		prev=temp;
	}
	return sum;
}
int main(){
	bignum a, b;
	scanf("%llu %llu", &a, &b);
	printf("%llu\n", sum(b)-sum(a-1));
}
