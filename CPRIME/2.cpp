#include<stdio.h>
#include<math.h>
#include<iostream>
//reduce memory consumption
using namespace std;
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
	a=new bool[50000001];

	for(int i=0; i<50000000; i++)
		a[i]=true;

	a[0]=false;
	a[1]=false;
	for(int i=2; i<=5000; i++)
	{
		if(a[i])
		{
		//	printf("hellp\n");
			for(int j=(2*i-1)*(2*i-1); j<=100000000; j+=2*(2*i-1))
				a[(j+1)/2]=false;
		}
	}
	int *b;
	b=new int[50000000];
	b[0]=0;b[1]=0; b[2]=2;
	for(int i=3; i<50000000; i++)
	{
		if(a[i])
		{
			b[i]=b[i-1]+1;
		}

		else
			b[i]=b[i-1];
		
	}
	
	for(int i=0; i<1000; i++)
	{
		int n;
		cin>>n;

		if(n==0)
			break;
		if(n==2)
			printf("188.5\n");
		else if(n>=99999999)
			printf("5.8\n");
		else
			printf("%.1f\n", abs1(b[(n+1)/2]-(n/log(n)))*100/b[(n+1)/2]);
		

	}
}


	/*for(int i=0; i<50000000; i++)
	{
		if(a[i])
			printf("%i\n", 2*i-1);
	}*/
	