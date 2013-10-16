#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

int main(){
	int c;
	int p0, p1, t, p;
	scanf("%i", &c);
	for(int i=0; i<c; i++){
		
		//scanf("%i %i %i %i\n", &p0, &p1, &t, &p);
		cin>>p0>>p1>>t>>p;
		double k=log(p1/(double)p0)/t;
		double ans=log(p/(double)p0)/k;
		printf("Scenario #%i: %.2f\n\n", i+1, ans);
	}
}