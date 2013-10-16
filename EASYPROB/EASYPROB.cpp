#include<stdio.h>
#include<math.h>
int hp2(int x)
{
	int ans=1;
	while(int(x/pow(2, ans))!=1)
		ans++;
	return ans;
}
void function(int x)
{
	if(x==1)
	{
		printf("2(0)");
	}
	else if(x==2)
	{
		printf("2");
	}
	else 
	{
		int y=hp2(x);
		int z=pow(2, y);
		if(y>1)
		{
			printf("2(");
				function(y);
				printf(")");
				if(x==z)
					return;
				else{
					printf("+");
					function(x-z);
				}
			}
			else
				printf("2+2(0)");
		}

	}
	int main()
	{
		int n;
		scanf("%i", &n);
		function(n);
		return 0;
	}