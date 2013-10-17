#include<stdio.h>
typedef long long bigint;
int main(){
	int t;
	scanf("%i", &t);
	while(t-->0){
		bigint n, a1, a2, b1, b2, c1, c2;
		scanf("%lli", &n);
		scanf("%lli %lli", &a1, &a2);
		scanf("%lli %lli", &b1, &b2);
		scanf("%lli %lli", &c1, &c2);
		bigint n_=n-a1-b1-c1;
		if(n_<0)
		{
			printf("0\n");
			continue;
		}
		if(n_==0)
		{
			printf("1\n");
			continue;
		}
		bigint A=a2-a1+1, B=b2-b1+1, C=c2-c1+1;
		bigint ans=(((2+n_)*(1+n_))/2)%1000000007;

		if(n_-A-B>=0){
			ans=(ans+(((2+n_-A-B)*(1+n_-A-B))/2))%1000000007;
		}
		if(n_-B-C>=0){
			ans=(ans+(((2+n_-B-C)*(1+n_-B-C))/2))%1000000007;
		}
		if(n_-C-A>=0){
			ans=(ans+(((2+n_-C-A)*(1+n_-C-A))/2))%1000000007;
		}
		if(n_-A>=0){
			ans=(ans-(((2+n_-A)*(1+n_-A))/2))%1000000007;
		}
		if(n_-B>=0){
			ans=(ans-(((2+n_-B)*(1+n_-B))/2))%1000000007;
		}
		if(n_-C>=0){
			ans=(ans-(((2+n_-C)*(1+n_-C))/2))%1000000007;
		}
		if(n_-A-B-C>=0){
			ans=(ans-(((2+n_-A-B-C)*(1+n_-A-B-C))/2))%1000000007;
		}
		printf("%lli\n", (ans+1000000007000000LL)%1000000007);
	}
}