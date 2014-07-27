#include<stdio.h>
int main()
{
	int c_no=1;
	while(1==1)
	{
		int n;
		scanf("%i", &n);
		if(n==-1)
			break;
		int c[n+1];
		for(int i=n; i>=0; i--)
			scanf("%i", &c[i]);
		int k;
		scanf("%i", &k);
		int x[k];
		for(int i=0; i<k; i++)
			scanf("%i", &x[i]);
		printf("Case %i:\n", c_no);
		for(int i=0; i<k; i++)
		{
			long long sum=0, term=1;
			for(int j=0; j<=n; j++)
			{
				sum+=term*c[j];
				term*=x[i];
			}
			printf("%lli\n", sum);
		}
		c_no++;
	}
	return 0;

}