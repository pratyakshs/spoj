#include<stdio.h>
#include<math.h>
typedef unsigned long long bigint;
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		unsigned long long int b;
		char A[1000];
		scanf("%s %lli", A, &b);
		int j;
		for(j=0; A[j]!='\0'; j++);
		int a=A[--j]-48;

		if (b==0)
			printf("1\n");
		else if(b%4==0)
			printf("%lli\n", bigint(pow(a, 4))%10);
		else
		printf("%lli\n", bigint(pow(a, b%4))%10);
	}
	return 0;
}