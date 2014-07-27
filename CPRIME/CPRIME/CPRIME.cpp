#include<stdio.h>
#include<math.h>
#include<array>
double abs1(double x)
{
	if (x>=0)
		return x;
	else
		return -x;
}
using namespace std;
int main()
{
	bool *a;
	a=new bool[100000001];

	for(int i=0; i<=100000000; i++)
		a[i]=true;
	a[0]=false;
	a[1]=false;
	for(int i=2; i<=10000; i++)
	{
		if(a[i])
		{
			for(int j=i*i; j<=100000000; j+=i)
				a[j]=false;
		}
	}
	int *b;
	b=new int[100000001];
	b[0]=0;
	for(int i=1; i<=100000000; i++)
	{
		if(a[i])
		{
			b[i]=b[i-1]+1;
		}
		else
			b[i]=b[i-1];
	}
	while(true)
	{
		int n;
		scanf("%i", &n);
		if(n==0)
			break;
		printf("%.1f\n", abs1(b[n]-(n/log(n)))*100/b[n]);
	}
}