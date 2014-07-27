#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef unsigned long long bignum;

bignum modexp(bignum base, bignum exponent, bignum modulo)
{
	bignum ans=1;
	while(exponent>0)
	{
		//printf("%llu)\n", exponent);
		if(exponent&1)
			ans=(ans*base)%modulo;
		exponent>>=1;
		base=(base*base)%modulo;
	}
	return ans;
}

bool isPrime(int n, int k=100)
{//Miller-Rabin
	if(n==2)
		return true;
	if(((n&1)==0 && n!=2) || (n<2))
		return false;
	else
	{//n=(2^s)*d + 1
		bignum s=0, d=n-1;
		while((d&1)==0)
		{
			d>>=1;
			s++;
		}
		srand(time(NULL));
		for(bignum i=0; i<k; i++)
		{
			//printf("%i)\n", i);
			bignum a = static_cast<double>(rand()) / RAND_MAX * (n-1) +1;
			
			bignum temp=d, mod=modexp(a, temp, n);
			while(temp!=n-1 && mod!=1 && mod!=n-1)
			{
				mod=(mod*mod)%n;
				temp<<=1;
				//printf("%llu)))\n", temp);
			}
			if(mod!=n-1 && (temp&1)==0)
				return false;
		}
		return true;
	}
}
int main(){
	int t;
	bignum n;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		scanf("%llu", &n);
		while(--n>0){
			if(isPrime(n))
			{
				printf("%llu\n", n);
				//break;
			}
		}
	}
}