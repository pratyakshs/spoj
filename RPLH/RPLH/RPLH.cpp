#include<stdio.h>
#include<math.h>
#define PI  3.14159265358979323846
using namespace std;

int main(){
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		int r, u;
		scanf("%i %i", &r, &u);
		float s2=r*9.806/(u*u);
		if(s2<=1){
			float theta=0.5*asin(s2)*180/PI;
			printf("Scenario #%i: %.2f\n", i+1, theta);
		}
		else{
			printf("Scenario #%i: -1\n", i+1);

		}
	}
}