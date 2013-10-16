#include<stdio.h>
typedef unsigned long long bigint;
bigint arr[100000];

bigint f(bigint n, bigint k)
{
	if(k==1)
		{
			arr[k]=n;
		return n;
	}
	else
	{
		if(arr[k]!=-1)
			return arr[k];
		else
		{
			bigint a=f(n,k-1);
			int b=a%2;
			bigint ans=(0.5 + 2.5 * b) * a + b;
			arr[k]=ans;
			return ans;
		}
	}
}

int main()
{
	unsigned long long n;
	
	while(scanf("%lli", &n)!=EOF)
	{
		for (int i = 0; i < 100000; ++i)
		{
			arr[i]=-1;
		}
		for(bigint i=1; ; i++)
		{
			if(f(n,i)==1)
			{
				printf("%lli\n", i);
				break;
			}
		}
	}
	return 0;
}