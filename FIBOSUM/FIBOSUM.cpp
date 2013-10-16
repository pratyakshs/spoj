#include<stdio.h>
#include<vector>
using namespace std;

typedef unsigned long long bignum;

vector<bignum> arr(10000000, -1);
bignum mulmod(bignum a,bignum b,bignum c){
	bignum x = 0,y=a%c;
	while(b > 0){

		if(b%2 == 1){
			x = (x+y)%c;
		}
		y = (y*2)%c;
		b >>= 1;
		//printf("%llu))\n", b);
	}
	return x%c;
}

bignum f(bignum n){
	if(n < 10000000 && arr[n]!=-1)
		return arr[n];
	bignum k=n/2;

	bignum fkp1=f(k+1);
	bignum fk=f(k);
	if(n<10000000){
		if(n&1){
			return arr[n]=(mulmod(fkp1, fkp1, 1000000007)+mulmod(fk, fk, 1000000007))%1000000007;
		}
		return arr[n]=mulmod(fk, ((2*fkp1-fk)+1000000007)%1000000007, 1000000007);
	}
	else{
		if(n&1){
			return (mulmod(fkp1, fkp1, 1000000007)+mulmod(fk, fk, 1000000007))%1000000007;
		}
		return mulmod(fk, ((2*fkp1-fk)+1000000007)%1000000007, 1000000007);
	}
}




int main()
{
	arr[0]=0; arr[1]=1; arr[2]=1; arr[3]=2; arr[4]=3;
	bignum t;
	scanf("%llu", &t);
	for(bignum i=0; i<t; i++)
	{
		bignum n,m;
		scanf("%llu %llu", &n, &m);

		printf("%llu\n", (f(m+2)-f(n+1)+ 1000000007)%1000000007);

	}
	return 0;
}