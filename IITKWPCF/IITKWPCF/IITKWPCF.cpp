#include<stdio.h>
#include<time.h> 
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
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
	}
	return x%c;
}

bignum modexp(bignum base, bignum exponent, bignum modulo)
{
	bignum ans=1;
	while(exponent>0)
	{
		if(exponent%2==1)
			ans=mulmod(ans, base, modulo);
		exponent>>=1;
		base=mulmod(base, base, modulo);
	}
	return ans;
}

bool isPrime(int n, int k=10)
{
	if(n==2)
		return true;
	if((n%2==0 && n!=2) || (n<2))
		return false;
	else
	{
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
	for(int i=0; i<t; i++)
	{
		bignum n;
		vector<bignum> v;
		scanf("%llu", &n);
		if(n%2)
		{
			printf("0\n");
			continue;
		}
		else
		{
			bignum n2=n/2;
			int upper=sqrt(n2);
			int j;
			for(j=2; j<upper; j++)
			{
				if(!(n2%j))
				{
					if(!isPrime(j))
						v.push_back(j);
					if(!isPrime(n2/j))
						v.push_back(n2/j);
				}
			}
			v.push_back(1);
			if(!isPrime(n2))
				v.push_back(n2);
			if(j*j==n2)
			{
				if(!isPrime(j))
					v.push_back(j);
			}

			sort(v.begin(), v.end());
			printf("%i ", v.size());
			for(int j=0; j<v.size(); j++)
				printf("%llu ", v[j]);
			printf("\n");
		}

	}
}