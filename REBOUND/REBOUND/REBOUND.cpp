#include<stdio.h>
#include<math.h>
using namespace std;
typedef long long bigint;

int main()
{	
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		bigint X,Y,Z;
		scanf("%lli %lli %lli", &X, &Y, &Z);
		bigint d2=X*X+Y*Y+2*Y*Z,root=bigint(sqrt(double(d2)));
		double x=double(X), y=double(Y), z=double(Z);
		if(root*root!= d2) printf("Not this time.\n");
		else{
			bigint num=z*x+z*root, den=2*z+y;
			if(num%den) printf("Not this time.\n");
			else 
				printf("%lli\n", num/den);
		}
	}
	return 0;
}