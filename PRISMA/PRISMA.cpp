#include<stdio.h>
#include<math.h>

using namespace std;
int main()
{
	int t; 
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int v;
		scanf("%i", &v);
		printf("%.10lf\n", 4.5*sqrt(3)*pow((4*v/(3*sqrt(3))), 2.0/3));
	}
}