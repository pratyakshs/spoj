#include<stdio.h>
#include<map>
using namespace std;
typedef unsigned long long bignum;
#define mdlo 1000000007ULL
map<bignum, bignum> arr;
bignum f(bignum n){
	if(arr.find(n)!=arr.end())
		return arr[n];
	bignum k=n>>1;
	bignum fkp1=f(k+1);
	bignum fk=f(k);
	if(n&1){
		return arr[n]=(fkp1*fkp1+fk*fk)%mdlo;
	}
	return arr[n]=(fk*(((fkp1*2ULL)+mdlo)-fk)+mdlo)%mdlo;
}
int main()
{
	arr[0]=0; arr[1]=1; arr[2]=1; arr[3]=2; arr[4]=3;
	bignum t;
	scanf("%llu", &t);
	for(bignum i=0; i<t; i++){
		bignum n;
		scanf("%llu", &n);
		printf("$%llu\n", (f(n+1)*f(n+2)-1)%mdlo);
//		printf("%llu\n", f(n));

	}
	return 0;
}
