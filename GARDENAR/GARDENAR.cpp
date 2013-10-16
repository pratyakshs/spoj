#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main(){
	int t;
	scanf("%i", &t);
	double a, b, c;
	for(int i=0; i<t; i++){
		scanf("%lf %lf %lf", &a, &b, &c);
		double x = (1.0/2)*(a*a+(sqrt(3)*sqrt(-(a*a*a*a)+(2*a*a*b*b)+(2*a*a*c*c)-(b*b*b*b)+(2*b*b*c*c)-(c*c*c*c)))+(b*b)+(c*c));
		printf("%.2lf\n", sqrt(3)*x/4);
	}
}