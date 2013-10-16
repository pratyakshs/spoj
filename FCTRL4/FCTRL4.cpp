#include<stdio.h>

//Had to do for inputs <= 10^100 :P
int D(unsigned long long n)
{
	int t=(n/10)%10;
	if(n<10)
	{
		switch(n)
		{
			case 1: return 1;
			case 2: return 2;
			case 3: return 6;
			case 4: return 4;
			case 5: return 2;
			case 6: return 2;
			case 7: return 4;
			case 8: return 2;
			case 9: return 8;
			case 0: return 1;
		}
	}
	if(t&1)
	{
		return (4*D((n/5))*D(n%10))%10;
	}
	else
		return (6*D((n/5))*D(n%10))%10;
}
int main()
{
	unsigned long long x;
	while(scanf("%llu", &x)!=EOF)
	{
		printf("%i\n", D(x));
	}
}