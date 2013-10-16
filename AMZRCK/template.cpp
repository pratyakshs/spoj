#include<stdio.h>
typedef unsigned long long bigint;
int arr[44];
int f(int n)
{
	if(n==0)
	{
		return 1;
	}
	if(n==1)
		return 2;

	if(arr[n]!=-1)
		return arr[n];

	else
	{
		
		arr[n]=f(n-1)+f(n-2);
		return arr[n];
	}

}

int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		for(int j=0; j<44; j++)
			arr[j]=-1;
		int n;
		scanf("%i", &n);
		printf("%i\n", f(n));
		
	}
	return 0;
}