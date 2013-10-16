//implements modexp, multmod, sum_of_divisors, and Miller-Rabin isPrime methods

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h> 
#include<math.h>

using namespace std;

typedef unsigned long long bignum;

/* this function calculates (a*b)%c taking into account that a*b might overflow 
for even larger numbers, write Bigint class*/

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

bignum sumdiv(bignum num)
{
	bignum sum=0, step=1;
	if(num%2) step=2;
	for(bignum i=1; i*i<=num; i+=step)
		sum += (num%i)? 0 : ((i*i==num)? i : i+num/i);
	return sum;
}

bool isPrime(int n, int k)
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
		srand(time(NULL));
		for(bignum i=0; i<k; i++)
		{
			//printf("%i)\n", i);
			bignum a = static_cast<double>(rand()) / RAND_MAX * (n-1) +1;
			/*
			bignum x=modexp(a, d, n);
			if(x==1 || x==n-1)
			{
				continue;
			}
			for(bignum r=1; r<s; r++)
			{
				x=modexp(x, 2, n);
				if(x==1)
					return false;
				if(x==n-1)
					continue;
			}n
			return false;*/
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

int main()
{
	int t;
	scanf("%i", &t);
	
	bignum arr[1000001];
	arr[0]=0; arr[1]=0; arr[2]=1;

	for(int j=3; j<=1000000; j++)
	{	
		if(sqrt(j)==int(sqrt(j)))
			{
				if(isPrime(sumdiv(j), 100))
					{
						arr[j]=arr[j-1]+1;
					//	printf("%i\n", j);
					}
					else arr[j]=arr[j-1];
			}
			else arr[j]=arr[j-1];
		//	printf("%llu\n", arr[j]);
	}



	for(int i=0; i<t; i++)
	{
		bignum a,b, count=0;
		scanf("%llu %llu", &a, &b);
		printf("%llu\n", arr[b]-arr[a-1]);
	}

	return 0;


}