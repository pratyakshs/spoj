#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		unsigned long long x, y;
		scanf("%llu %llu", &x, &y);
		unsigned long long g = __gcd(x, y), x1 = x/g, y1 = y/g;
		printf("%llu\n", x1*y1/__gcd(x1, y1));
	}
	return 0;
}
