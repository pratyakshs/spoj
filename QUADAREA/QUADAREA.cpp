#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t; 
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		float a, b, c, d;
		scanf("%f %f %f %f", &a, &b, &c, &d);
		float s=(a+b+c+d)/2;
		printf("%f\n", sqrt((s-a)*(s-b)*(s-c)*(s-d)));
	}
}