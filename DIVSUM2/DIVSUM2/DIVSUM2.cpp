//implements modexp, multmod, sum_of_divisors, and Miller-Rabin isPrime methods
//Pollard's rho factorization.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h> 
#include<math.h>

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

bool isPrime(bignum n, bignum k)
{//Miller-Rabin
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
		//printf("%llu=(2^%llu)*%llu+1\n", n, s, d);
		srand(time(NULL));
		for(bignum i=0; i<k; i++)
		{

			bignum a = static_cast<double>(rand()) / RAND_MAX * (n-1) +1;
			
			bignum temp=d, mod=modexp(a, temp, n);
			while(temp!=n-1 && mod!=1 && mod!=n-1)
			{
				mod=mulmod(mod, mod, n);
				temp<<=1;
				//printf("%llu)))\n", temp);
			}
			if(mod!=n-1 && temp%2==0)
				return false;
		}
		return true;
	}
}


/*Naive method. O(sqrt(n)). Won't pass.
bignum sumdiv(bignum num)
{
	bignum sum=0, step=1;
	if(num%2) step=2;
	for(bignum i=1; i*i<=num; i+=step)
		sum += (num%i)? 0 : ((i*i==num)? i : i+num/i);
	return sum;
}*/


int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		bignum n;
		scanf("%llu", &n);
		printf("%llu\n", sumdiv(n)-n);
	}

	return 0;


}