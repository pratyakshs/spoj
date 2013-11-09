#include<stdio.h>
#include<map>
using namespace std;
int main(){
	map<double, int> m;
	double val=0;
	for(double i=2; i<278; i++){
		val+=(1.0/i);
		m[val]=i-1;
	}
	double x;
	while(scanf("%lf", &x)!=EOF){
		if(x==0)
			return 0;
		map<double, int>::iterator it=m.lower_bound(x);
		printf("%i card(s)\n", it->second);
	}
}
