//Sieve of eratosthenes
#include<math.h>
#include<stdio.h>
#include<vector>

using namespace std;

vector<bool> v;
//checking only odd numbers. 

int main()
{
	
	int n;
	scanf("%i", &n);

	int n_=(n-1)/2;

	if(n_>v.size())
		v.resize(n_,1);

	for(int i=3; i<=sqrt(n); i+=2){
		for(int j=i*i; j<=n; j+=2*i){
			v[(j-3)/2]=false;
		}
	}

	printf("%i\n", 2);

	for(int i=0; i<v.size(); i++){
		if(v[i])
			printf("%i\n", 2*i+3);
	}

	
	return 0;
}