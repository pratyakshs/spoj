#include<bits/stdc++.h>
using namespace std;
#define modulo 1000000007
typedef unsigned long long ull;
int main(){
	ull **table=new ull*[101];
	for(int i=1; i<101; i++){
		table[i]=new ull[4951];
	}
	table[1][1]=0;
	table[1][0]=1;
	for(int i=2; i<101; i++)
		table[i][0]=1;
	for(int i=2; i<101; i++){
		ull m=(i*i-i+2)>>1;
		for(int j=1; j<=m; j++){
			if(j<i)
				table[i][j]=(table[i][j-1]+table[i-1][j])%modulo;
			else
				table[i][j]=(modulo+table[i][j-1]+table[i-1][j]-table[i-1][j-i])%modulo;
		}
	}
	int t, n, k;
	scanf("%i", &t);
	for(int tt=1; tt<=t; tt++){
		scanf("%i %i", &n, &k);
		printf("%llu\n", table[n][k]);
	}
	return 0;
}
	
