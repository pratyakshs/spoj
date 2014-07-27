#include<stdio.h>
typedef unsigned long long bignum;
bignum arr[50];
bignum hanoi(int n){
	if(arr[n])
		return arr[n];
	return arr[n]=3*hanoi(n-1)+2;
}
int main(){
	for(int i=1; i<50; i++)
		arr[i]=0ULL;
	arr[0]=0ULL;
	arr[1]=2ULL;
	int t,n;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		scanf("%i", &n);
		printf("%llu\n", hanoi(n));

	}

}