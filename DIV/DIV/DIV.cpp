#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

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
	
}