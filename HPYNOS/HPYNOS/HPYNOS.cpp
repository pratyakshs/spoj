#include<stdio.h>
int main()
{	
	unsigned int n, i;
	scanf("%i", &n);
	if(n==1)
		printf("1\n");
	else
	{
	while(n>=10 || n==7)
	{
		i++;
		unsigned int x=n, sum=0;
		while(x>0)
		{
			sum+=(x%10)*(x%10);
			x/=10;
		}
		n=sum;
	}
	if(n==1)
		printf("%i\n", i);
	else
		printf("-1\n");
}
	return 0;
}