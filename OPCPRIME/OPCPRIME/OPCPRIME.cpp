#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


typedef unsigned long long bignum;


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

bignum modexp(bignum base, bignum exponent, bignum modulo)
{//implement for the case when base is an nxn matrix. Targeted running time: O(n^3 log(exponent)).
	bignum ans=1;
	while(exponent>0)
	{
		//printf("%llu)\n", exponent);
		if(exponent%2==1)
			ans=mulmod(ans, base, modulo);
		exponent>>=1;
		base=mulmod(base, base, modulo);
	}
	return ans;
}

bool isPrime(bignum n, int k)
{
	if(n==2)
		return true;
	if((n%2==0 && n!=2) || (n<2))
		return false;
	else
	{//n=(2^s)*d + 1
		bignum s=0, d=n-1;
		while(d%2==0)
		{
			d>>=1;
			s++;
		}
		srand(time(NULL));
		for(bignum i=0; i<k; i++)
		{
			
			bignum a = static_cast<double>(rand()) / RAND_MAX * (n-1) +1;
			
			bignum temp=d, mod=modexp(a, temp, n);
			while(temp!=n-1 && mod!=1 && mod!=n-1)
			{
				mod=mulmod(mod, mod, n);
				temp<<=1;
				
			}
			if(mod!=n-1 && temp%2==0)
				return false;
		}
		return true;
	}
}

int main()
{
	bool *a;
	a=new bool[500001];

	for(int i=0; i<500000; i++)
		a[i]=true;

	a[0]=false;
	a[1]=false;
	for(int i=2; i<=500; i++)
	{
		if(a[i])
		{
		//	printf("hellp\n");
			for(int j=(2*i-1)*(2*i-1); j<=1000000; j+=2*(2*i-1))
				a[(j+1)/2]=false;
		}
	}
	unsigned long long n;
	scanf("%llu", &n);
	if(n%2==0)
	{
		printf("2\n");
	}
	for(int i=0; i<500001; i++)
	{
		if(a[i])
		{
			if(n%(2*i-1)==0)
				printf("%i\n", 2*i-1);
		}
	}
	if(isPrime(n, 20))
	{
		printf("%llu\n", n);
	}


}
