#include<stdio.h>

typedef long long bignum;
struct pairxy{
	int x,y;
	pairxy(int a, int b){
		x=a, y=b;
	}
};
pairxy bezout(int a, int m){
		//returns the solution (x,y) of ax+my=1
	if(m==0)
		return pairxy(1, 0);
	pairxy p=bezout(m, a%m);
	return pairxy(p.y, (p.x-(p.y*(a/m))));
}

int modInv(int &a){
	pairxy p=bezout(a,1000000007);
	if(p.x<0)
		return p.x+1000000007;
	return p.x;
}


int** bin = new int*[1001];


bignum calcBin(int n, int k){
	if(k>n)
		return 0;
	if(bin[n][k]!=-1)
		return bin[n][n-k]=bin[n][k];
	if(bin[n][n-k]!=-1)
		return bin[n][k]=bin[n][n-k];
	return bin[n][k]=bin[n][n-k]=(calcBin(n-1, k)+calcBin(n-1, k-1))%1000000007;
}


int main(){
	for(int i = 1; i < 1001; ++i)
		bin[i] = new int[1001];

	for(int i=1; i<1001; i++)
		for(int j=2; j<1001; j++)
			bin[i][j]=-1;

		for(int i=1; i<1001; i++){
			bin[i][0]=1;
			bin[i][1]=i;
		}

		bignum t;
		scanf("%lli", &t);
		for(bignum i=0; i<t; i++){
			int n, k, k_;
			scanf("%i %i", &n, &k);
			printf("%lli\n", (((calcBin(n, k)*calcBin(n, k-1))%1000000007)*modInv(n))%1000000007);
		}
	}