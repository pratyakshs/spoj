#include<stdio.h>
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;
int y1_,y2,y3,y4;
double pol(bigint x)
{
	return (x-2.0)*(x-3.0)*(x-4.0)*(-y1_/6.0)+(x-1.0)*(x-3.0)*(x-4.0)*y2/2.0+(x-2.0)*(x-1.0)*(x-4.0)*(-y3/2.0)+(x-2.0)*(x-3.0)*(x-1.0)*y4/6.0;
}
int main()
{	
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int n;
		bool flag=true;
		scanf("%i", &n);
		int y;
		if(n<=4)
		{
			for(int i=0; i<n; i++)
				scanf("%i", &y);
		printf("YES\n");
			continue;
		}
		
		
		scanf("%i %i %i %i", &y1_, &y2, &y3, &y4);
		for(int i=5; i<=n; i++)
		{
			scanf("%i", &y);
			//printf("%f\n",pol(i));
			if( flag && pol(i)!=y )
				flag=false;
		}
		if(y1_==y2 && y2==y3 && y3==y4 && y4==0)
			flag=false;
		if(flag)
			printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
//add condition if all y_i are zero==>NO