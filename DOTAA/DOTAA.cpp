#include<stdio.h>
int main()
{
	int t; 
	scanf("%i", &t);
	for(int k=0; k<t; k++)
	{
		int n, m, d;
		scanf("%i", &n);
		scanf("%i", &m);
		scanf("%i", &d);
		int h[n];
		for(int l=0; l<n; l++)
		{
			scanf("%i", &h[l]);
		}
		bool flag;
		for(int i=0; i<m; i++)
		{
			int j;
			for(j=0; j<n; j++)
			{
				if(h[j]>d)
				{
					h[j]-=d;
					break;
				}
			}
			if(j>n) {
				flag=false;
				break;
			}
		}
		if(flag)
		{
			printf("%s\n", "YES");
		}
		else
		{
			printf("%s\n", "NO");
		}
	}
	return 0;
}