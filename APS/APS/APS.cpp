#include<stdio.h>
typedef unsigned long long bignum;

bignum *table=new bignum[10000001];
bool *primality=new bool[10000010];
int *smallestPrimeDiv=new int[10000010];

int main(){
	//Sieve
	for(int i=0; i<10000010; i++)
		primality[i]=true, smallestPrimeDiv[i]=0;
	for(int i=2; i<10010; i++)
		if(primality[i]){
			for(bignum j=i*i; j<10000010; j+=i){
				primality[j]=false;
				if(smallestPrimeDiv[j]==0)
					smallestPrimeDiv[j]=i;
			}
		}
	for(int i=2; i<10000010; i++)
		if(primality[i])
			smallestPrimeDiv[i]=i;
	int t, n;
	scanf("%i", &t);
	table[0]=table[1]=0;
	for(int i=2; i<=10000000; i++)
		table[i]=table[i-1]+smallestPrimeDiv[i];

	while(t-->0){
		scanf("%i", &n);
		printf("%llu\n", table[n]);
	}
}


