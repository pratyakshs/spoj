#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%i", &n);

	int n_=(n-1)/2;
	bool sieve[n_];//sieve for all odd numbers uptil n

	for(int i=0; i<n_; i++)
		sieve[i]=true;

	for(int i=3; i<=sqrt(n); i+=2){
		if(sieve[(i-3)/2])
		{
			for(int j=i*i; j<=n; j+=2*i){
				sieve[(j-3)/2]=false;
			}
		}
	}
	int j=1, t, count=0;
	do{
		t=n/pow(2, j);
		count+=t;
		j++;
	}while(t>0);
	printf("%s", "2^");
	printf("%i", count);

	for(int i=0; i<n_; i++)
	{
		if(sieve[i])
		{
			j=1, count=0;
			do{
				t=n/pow(2*i+3, j);
				count+=t;
				j++;
			}while(t>0);
			printf(" * %i", 2*i+3);
			printf("^%i", count);

		}
	}


	return 0;
}