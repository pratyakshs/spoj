//Sieve of eratosthenes
#include<math.h>
#include<stdio.h>
#include<vector>

using namespace std;

vector<bool> v(1, true);
//checking only odd numbers. 

int main()
{
	int t;
	scanf("%i", &t);
	for(int k=0; k<t; k++){
		int m,n;
		scanf("%i", &m);
		scanf("%i", &n);
		if(m==1) m=2;		

		int n_=(n-1)/2;

		if(n_>v.size())
		{
			v.resize(n_,1);
		}
		for(int i=3; i<=sqrt(n); i++){
			for(int j=i*i; j<=n; j+=2*i){
				v[(j-3)/2]=false;
			}
		}

		if(m==2) printf("%i\n", 2);

		for(int i=(m-3)/2; i<=(n-3)/2; i++){
			if(v[i])
				printf("%i\n", 2*i+3);
		}

	}
		return 0;
	}