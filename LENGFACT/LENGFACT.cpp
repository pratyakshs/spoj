#include<stdio.h>
#define pi 3.1415926535897932384626433832795028841971693993751058
#define e 2.718281828459045235360287471352662497757247093699959574966967
#include<math.h>
typedef unsigned long long bigint;
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		bigint n;

		scanf("%lli", &n);
		switch(n)
		{
			case 0: printf("%i\n", 1); break;
			case 1: printf("%i\n", 1); break;
			case 2: printf("%i\n", 1); break;
			case 3: printf("%i\n", 1); break;
			case 4: printf("%i\n", 2); break;
			case 5: printf("%i\n", 3); break;
			default: printf("%lli\n", bigint(log10(sqrt(2*pi))+(double(n)+0.5)*log10(double(n))-double(n)*log10(e))+1); break;
		}
		

	}
	return 0;
}