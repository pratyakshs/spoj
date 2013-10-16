#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;

long long coeff(long long n, long long r)
{

	
	long long j=0;
	//printf("n=%lli, r=%lli\n", n, r);
	double numerator=1;
	for(long long i=0, j=1; i<=r-1 &&  j<=r; i++, j++)
	{
		numerator*=double(n+i)/double(j);
	}
	//printf("ans=%lf\n", numerator);
	return numerator;
}

int main()
{
	long long m, n;
	vector<int> d;
	scanf("%lli %lli", &m, &n);
	long long pow_find=n;
	for(long long i=0; i<m; i++)
	{
		long long A, B;
		scanf("%lli %lli", &A, &B);
		//printf("%lli\n", coeff(A,B));
		d.push_back(B-A+1);
		pow_find-=A;
	}
	vector<int> sign(2);
	sign[0]=1; sign[1]=-1;
	vector<int> pows(2);
	pows[0]=d[0]; pows[1]=0;
	
	for(long long i=1; i<m; ++i)
	{
		long long psize=pows.size();
		for(long long j=0; j<psize; j++)
		{
			pows.push_back(pows[j]);
		//	printf("loopA: i=%lli, j=%lli\n", i, j);
				}
		long long ssize=sign.size();		
		for(long long j=0; j<ssize; ++j)
		{
			sign.push_back(-(sign[j]));
		//	printf("loopB: i=%lli, j=%lli\n", i, j);
		}
		for(long long j=0; j<(pows.size()/2); ++j)
		{
			pows[j]+=d[i];
			//printf("loopC: i=%lli, j=%lli\n", i, j);
		}

	}

	long long ans=0;
	//printf("powfind::%i\n", pow_find);
	for(long long i=0; i<pows.size(); i++)
	{
		if(pow_find>=pows[i])
		{
			ans+=(sign[i]*coeff(m, pow_find-pows[i]));
		}
	}
	printf("%lli", -((long long)ans));


	
}