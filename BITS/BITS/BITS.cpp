#include<bits/stdc++.h>
using namespace std;
inline int bits(int i){
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
int main(){
	int t, n;
	scanf("%i", &t);
	int table[1001];
	table[0];
	for(int i=1; i<1001; i++) table[i]=table[i-1]+bits(i);
	while(t--){
		scanf("%i", &n);
		printf("%i\n", table[n]);
	}
	return 0;
}

