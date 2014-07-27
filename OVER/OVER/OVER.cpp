#include<stdio.h>

typedef unsigned long long bignum;

bignum table[50][3];

bignum calc(int n, int first){

	if(table[n-1][first]!=-1)
		return table[n-1][first];

	if(first==0){
		table[n-1][first]=calc(n-1, 0)+calc(n-1, 1);
		return table[n-1][first];
	}
	if(first==1){
		table[n-1][first]=calc(n-1, 0)+calc(n-1, 1)+calc(n-1, 2);
		return table[n-1][first];
	}
	if(first==2){
		table[n-1][first]=calc(n-1, 2)+calc(n-1, 1);
		return table[n-1][first];
	}

}
int main(){
	for(int i=0; i<50; i++)
		table[i][0]=table[i][1]=table[i][2]=-1;
	table[0][0]=table[0][1]=table[0][2]=1;


	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		int n;
		scanf("%i", &n);
		printf("%llu\n", calc(n, 0)+calc(n, 1)+calc(n, 2));

	}
}