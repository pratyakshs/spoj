#include<bits/stdc++.h>
using namespace std;
typedef long long bignum;
inline void readInt (bignum &result) {
	result = 0;
	char ch=getchar_unlocked();
	while (true) {
		if (ch<'0' || ch>'9') break;
		result = result*10 + (ch - '0');
		ch=getchar_unlocked();
	}
}
int main(){
	bignum t, n;
	readInt(t);
//	printf("%llu\n", t);
	for(bignum ii=1; ii<=t; ii++){
		readInt(n);
		if(n==0){
			printf("Case %llu: 0\n", ii);
			continue;
		}
		bignum arr[n];
		for(bignum i=0; i<n; i++)
			readInt(arr[i]);
		bignum table[n][2];
		table[0][1]=arr[0];
		table[0][0]=0;
		for(bignum i=1; i<n; i++){
			table[i][1]=arr[i]+table[i-1][0];
			table[i][0]=max(table[i-1][0], table[i-1][1]);
		}
		printf("Case %llu: %llu\n", ii, max(table[n-1][0], table[n-1][1]));
	}
}
