#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long bignum;

int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		bignum n, k;
		scanf("%llu %llu", &n, &k);
		bool sieve[n+1];
		int s=sqrt(n);
		for(int i=0; i<=n; i++)
			sieve[i]=true;
		for(int i=2; i<=s; i++){
			if(sieve[i]){
				for(int j=i*i; j<=n; j+=i)
					sieve[j]=false;
			}
		}
		bignum ans[n+1], aux[n+1], count[n+1];
		count[0]=count[1]=0;
		for(int i=2; i<=n; i++){
			if(sieve[i])
				count[i]=count[i-1]+1;
			else
				count[i]=count[i-1];
		}
		
		int start=2;
		for(; start<=n && count[start]<k; start++);
		if(start<=n){
			aux[start]=1;
			for(int i=0; i<start; i++)
				aux[i]=0;
			for(int i=start+1; i<n+1; i++){
				if(sieve[i]){
					int j;
					for(j=aux[i-1]+2; j<=n; j++){
						if(sieve[j])
							break;
					}
					aux[i]=j-1;			
				}
				else
					aux[i]=aux[i-1];
			}
		}
		else 
			for(int i=0; i<=start; i++)
				aux[i]=0;
		ans[1]=0;
		for(int i=2; i<=n; i++)
			ans[i]=ans[i-1]+aux[i];
//		for(int i=0; i<=n; i++){
	//		printf("aux[%i]=%llu\n", i, aux[i]);
	//	}
		if(k) 
			printf("%llu\n", ans[n]);
		else 
			printf("%llu\n", ((n-1)*n)>>1);

	}
	return 0;
}
