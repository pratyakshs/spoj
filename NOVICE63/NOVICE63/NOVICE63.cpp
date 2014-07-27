#include<stdio.h>
typedef unsigned long long bignum;
int p2(bignum n){
	int i=0;
	while(n){
		n>>=1;
		i++;
	}
	return i;
}
bignum** bin = new bignum*[64];


bignum calcBin(int n, int k){
	if(k>n)
		return 0;
	if(bin[n][k]!=-1)
		return bin[n][n-k]=bin[n][k];
	if(bin[n][n-k]!=-1)
		return bin[n][k]=bin[n][n-k];
	return bin[n][k]=bin[n][n-k]=(calcBin(n-1, k)+calcBin(n-1, k-1));
}

bignum table[64];
bignum calc(int bits){
	if(table[bits]!=-1)
		return table[bits];
	if(bits&1)
		return table[bits]=calc(bits-1);
	return table[bits]=calc(bits-1)+calcBin(bits-1, bits>>1);
}

int main(){
	for(int i = 1; i < 64; ++i)
		bin[i] = new bignum[64];

	for(int i=1; i<64; i++)
	{
		for(int j=2; j<64; j++)
			bin[i][j]=-1;
	}

	for(int i=1; i<64; i++){
		bin[i][0]=1;
		bin[i][1]=i;
	}

	for(int i=0; i<=63; i++)
		table[i]=-1;
	table[0]=0;
	table[1]=0;
	table[2]=1;
	int t;
	bignum n;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		scanf("%llu", &n);
		if(n==2)
			{printf("1\n"); continue;}
		printf("%llu\n", calc(p2(n)-1));
	}
}