#include<stdio.h>
typedef unsigned long long bignum;

bignum table[30][30];

bignum stirling(int n, int k){
	if(k>n)
		return 0;
	if(table[n][k]!=-1)
		return table[n][k];
	return table[n][k]=k*stirling(n-1, k)+stirling(n-1, k-1);
}
int main(){
	for(int i=0; i<30; i++)
		for(int j=0; j<30; j++)
			table[i][j]=-1;
		for(int i=0; i<30; i++)
			table[0][i]=0, table[i][0]=0;
		table[0][0]=1;

		int t, n, k;
		scanf("%i", &t);
		while(t-->0){
			scanf("%i %i", &n, &k);
			printf("%llu\n", stirling(n,k));
		}
	}