//Solution to prime1
#include<math.h>
#include<iostream>
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
	cin>>t;
	for(int k=0; k<t; k++){
		
		bigint m,n;
		cin>>m>>n;
		if(m==n && n==1) continue;
		if(m==1) m=2;
		if(m==2) cout<<"2\n";
		if(n==2) continue;
		if(m==n)
		{
			bool flag=true;
			for(int i=2; i<=sqrt(n); i++)
			{
				if(n%i==0){
					flag=false;
					break;
				}
			}
			if(flag)
				cout<<n<<endl;
			continue;
		}
		n++;

		bigint m2=sqrt(n);
		bigint m_=(m2-1)/2;
		bigint n_=(n-m)/2;
		bool v1[m_], v2[n_];

		//calculating primes till sqrt (m)
		for(bigint i=3; i<=sqrt(m2); i+=2){
			if(v1[(i-3)/2]){
				for(bigint j=i*i; j<=m2; j+=2*i){
					v1[(j-3)/2]=false;
				}
			}
		}

		for(bigint i=0; i<m_; i++){
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

		for(bigint i=0; i<n_; i++){
			if(v2[i]){
				bigint p=m+2*i+1;

				for(bigint j=p*p; j<=n; j+=2*p)
					v2[(j-m-1)/2]=false;

			}
		}

		
		for(bigint i=0; i<n_; i++){
			if(v2[i])
				cout<<m+1+2*i<<endl;
		}

	}
	return 0;
}