#include <stdio.h>
#define size 10
int str[size];

typedef long long int bigint;

void add(int a[size], int b[size], int c[size])
{
	int carry=0;

	for(int i=0; i<size; i++)
			c[i]=0;

	for(int i=size-1; i>=0; i--)
	{
		c[i]=(a[i]+b[i]+carry)%10;
		carry=(a[i]+b[i]+carry)/10;
	}
}

void leftshift(int a[size], int k, int c[size])
{
	for(int i=0; i<size-k; i++)
	{
		c[i]=a[i+k];
	}
	for(int i=size-k; i<size; i++)
	c[i]=0;
}

void convert2arr(bigint x, int c[size])
{
	int j=size-1;

	for(int i=0; i<size; i++)
		c[i]=0;

	while(x>0)
	{
		c[j]=x%10;
		x/=10;
		j--;
	}
}

void print(int a[size]){
	for(int i=0; i<size; i++)
		printf("%i", a[i]);
}

void mult1(int a[size], int n, int c[size])
{
	int carry=0;
	for(int i=size-1; i>=0; i--)
	{
		c[i]=(a[i]*n+carry)%10;
		carry=(a[i]*n+carry)/10;
	}
}
void mult(int a[size], int n, int c[size])
{
	for(int i=0; i<size; i++)
		c[i]=0;

	int *cmult=new int[size];

	while(n>0){
		mult1(a, n%10, cmult);
		add(c, cmult, c);
		n/=10;
	}
}
int main() {

	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int x;
		scanf("%i", &x);
		for(int j=0; j<size-1; j++)
			str[j]=0;
		str[size-1]=1;
		for(int j=x; j>0; j--)
		{
			mult(str, j, str);
		}
		print(str);
		printf("\n");

	}
	return 0;
}

