
#include<stdio.h>

int reverse(int x)
{
	int ans=0;
	while(x>0)
	{
		ans*=10;
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main()
{
	int N;
	scanf("%i",&N);
	for(int i=0; i<N; i++)
	{
		int a, b;
		scanf("%i", &a);
		scanf("%i", &b);
		printf("%i\n", reverse(reverse(a)+reverse(b)));
	}

return 0;
}
