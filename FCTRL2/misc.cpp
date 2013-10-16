#include <stdio.h>
#define size 10
int str[size];

typedef long long int bigint;

void add(int a[size], int b[size], int c[size])
{
	int carry=0;
	int *d=new int[size];

	for(int i=0; i<size; i++)
		d[i]=0;

	for(int i=size-1; i>=0; i--)
	{
		d[i]=(a[i]+b[i]+carry)%10;
		carry=(a[i]+b[i]+carry)/10;
	}
	for(int i=0; i<size; i++)
		c[i]=d[i];
}

void leftshift(int a[size], int k, int c[size])
{
	int *d=new int[size];

		for(int i=0; i<size; i++)
			d[i]=0;
	for(int i=0; i<size-k; i++)
	{
		d[i]=a[i+k];
	}
	for(int i=size-k; i<size; i++)
	d[i]=0;
	for(int i=0; i<size; i++)
			c[i]=d[i];

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
	int *d=new int[size];

	for(int i=0; i<size; i++)
		d[i]=0;

	int carry=0;
	for(int i=size-1; i>=0; i--)
	{
		d[i]=(a[i]*n+carry)%10;
		carry=(a[i]*n+carry)/10;
	}
	for(int i=0; i<size; i++)
			c[i]=d[i];
}
void mult(int a[size], int n, int c[size])
{
	int *d=new int[size];
	for(int i=0; i<size; i++)
		d[i]=0;

	int *cmult=new int[size];

	while(n>0){
		mult1(a, n%10, cmult);
		add(d, cmult, d);
		n/=10;
	}
	for(int i=0; i<size; i++)
		c[i]=d[i];
}
int main() {

	int t;
	for(int j=0; j<size-1; j++)
				str[j]=0;
			str[size-1]=1;
	scanf("%i", &t);
	mult(str, t, str);
	print(str);
	return 0;
}

