#include<stdio.h>
#include<math.h>

int f(int x)
{
	int ans=0;
	for(int i=1; i<=sqrt(x); i++)
	{
		if(x%i==0)
		{
			ans++;
		}
	}
	return ans;
}
int main()
{
	int n;
	scanf("%i", &n);
	if(n>1)
	{
		int sum=1;
		for(int i=2; i<=n; i++)
		{
			sum+=f(i);
		}
		printf("%i", sum);
	}
	else printf("1");
	return 0;
}