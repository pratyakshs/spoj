//Solution to prime1
#include<math.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

typedef long long int bigint;

using namespace std;

bigint function(bigint m, bigint p)
{
	if(p*p>=m+1)
		return 0;
	else return bigint(ceil(double((m+1-p*p))/((double)(2*p))));
}

//checking only odd numbers. 
//v1 is for primes uptill sqrt(m)

int main()
{
	int t;
	scanf("%i", &t);
	for(int k=0; k<t; k++){
		vector<bool> v1, v2;
		bigint m,n;
		scanf("%lli", &m);
		scanf("%lli", &n);
		n++;
		if(m==1) m=2;		

		bigint m2=sqrt(n);
		bigint m_=(m2-1)/2;

		v1.resize(m_,true);

		bigint n_=(n-m)/2;

		v2.resize(n_, true);

		//calculating primes till sqrt (m)
		for(bigint i=3; i<=sqrt(m2); i+=2){
			if(v1[(i-3)/2]){
				for(bigint j=i*i; j<=m2; j+=2*i){
					v1[(j-3)/2]=false;
				}
			}
		}

		for(bigint i=0; i<v1.size(); i++){
			if(v1[i]){
				bigint p=2*i+3;
				int k=function(m, p);
				//printf(" %i\n", k);
				for(bigint j=p*(p+2*k); j<=n; j+=2*p)
				{
						v2[(j-m-1)/2]=false;
				}
			}
		}

		for(bigint i=0; i<=v2.size(); i++){
			if(v2[i]){
				bigint p=m+2*i+1;

				for(bigint j=p*p; j<=n; j+=2*p)
					v2[(j-m-1)/2]=false;

			}
		}

		if(m==2) printf("%i\n", 2);

		for(bigint i=0; i<v2.size(); i++){
			if(v2[i])
				printf("%lli\n", m+1+2*i);
		}

	}
	return 0;
}