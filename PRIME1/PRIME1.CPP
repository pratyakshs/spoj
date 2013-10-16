//Just applied trial division to each successive odd number.
#include<stdio.h>
#include<math.h>
using namespace std;
typedef long long int bigint;
int main()
{
	int t;
	scanf("%i", &t);
	for(int k=0; k<t; k++)
	{

		bigint n, m;
		bool flag=1;		
		scanf("%lli", &m);
		scanf("%lli", &n);
		if(m==1) m=2;
		for(bigint i=m; i<=n; i++){
			flag=1;
			if(i%2==0 && i!=2) flag=0;
			else
				for(int j=3; j<=sqrt(i); j+=2){
					if(i%j==0){
						flag=0;
						break;
					}
					
				}
				if(flag)
					printf("%lli\n", i);

			}
			printf("\n");

		}
		return 0;
	}