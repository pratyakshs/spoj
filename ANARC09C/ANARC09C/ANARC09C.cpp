#include<bits/stdc++.h>
using namespace std;
#define numprimes 78498
int main(){
	bool arr[1000001];
	for(int i=0; i<1000001; i++)
		arr[i]=true;
	int s=sqrt(1000001);
	for(int i=2; i<=s; i++){
		if(arr[i]){
			for(int j=i*i; j<1000001; j+=i)
				arr[j]=false;
		}
	}
	int primes[numprimes];
	for(int i=2, j=0; i<1000001; i++)
		if(arr[i])
			primes[j++]=i;
	int a, b, ii=0;
	while(scanf("%i %i", &a, &b)!=EOF){
		ii++;
		if(a==0)
			break;
		map<int, int> facta, factb;
		for(int i=0; a>0 && i<numprimes; i++)
			if(a%primes[i]==0){
				facta[primes[i]]++;
				a/=primes[i];
				i--;
			}
		for(int i=0; b>0 && i<numprimes; i++)
			if(b%primes[i]==0){
				factb[primes[i]]++;
				b/=primes[i];
				i--;
			}
		int count=factb.size(), dist=0;
		for(map<int, int>::iterator ita=facta.begin(); ita!=facta.end(); ita++){
			map<int, int>::iterator itb=factb.find(ita->first);
			if(itb==factb.end()){
				count++;
				dist+=ita->second;
			}
			else
				dist+=abs(itb->second-ita->second);
		}
		for(map<int, int>::iterator itb=factb.begin(); itb!=factb.end(); itb++)
			if(facta.find(itb->first)==facta.end())
				dist+=itb->second;
		printf("%i. %i:%i\n", ii, count, dist);
	}	
				
	//printf("%i\n", count);
}
