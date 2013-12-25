#include<bits/stdc++.h>
using namespace std;

int main(){
	int fermat_primes[]={3, 5, 17, 257, 65537};
	int t, n;
	scanf("%i", &t);
	while(t--){
		int prime_power[]={0, 0, 0, 0, 0};
		scanf("%i", &n);
		for(int i=0; i<5; i++){
			if(n%fermat_primes[i]==0){
				n/=fermat_primes[i];
				prime_power[i]++;
				i--;
			}
		}
		bool flag=true;
		while(n>1){
			if(n&1){
				flag=false;
				break;
			}
			n=n>>1;
		}
		for(int i=0; i<5; i++){
			if(prime_power[i]>1)
				flag=false;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
