#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		long long x;
		scanf("%lli", &x);
		double n=(-1.0+sqrtl(1.0-4.0*(2.0-2.0*x)))/2.0;
		long long c=(long long)n;
		if(0.5*((c-1)*(c-1)+c+1)>=x && c-1 >=0)
			printf("%lli\n", c-1);
		else if(0.5*(c*c+c+2)>=x && c>=0)
			printf("%lli\n", c);
		else if(0.5*((c+1)*(c+1)+c+3)>=x)
			printf("%lli\n", c+1);
		else if(0.5*((c+2)*(c+2)+c+4)>=x)
			printf("%lli\n", c+2);
	}
	return 0;
}
