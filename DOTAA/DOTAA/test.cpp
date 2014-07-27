#include<stdio.h>
int main()
{
	int t; 
	scanf("%i", &t);
	int p[t];
	for(int k=0; k<t; k++)
	{
		scanf("%i", &p[k]);
	}
	int j;
	for(j=0; j<t; j++)
	{
		if(p[j]==0)
			break;
	}
	printf("\n%i\n", j);
	return 0;

}