#include<stdio.h>
#include<math.h>
using namespace std;

int main() {

	int n;
	scanf("%i",&n);
	for(int i=0; i<n; i++)
	{
		int x, count=0, j=1, t=1;
		scanf("%i", &x);
		do{
			t=x/pow(5, j);
			count+=t;
			j++;
		}while(t>0);
			printf("\n%i",count);

		}
	return 0;
	}
