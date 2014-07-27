#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long unt64;
int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		unt64 x, y, g;
		scanf("%llu %llu", &x, &y);
		unt64 l = (x*y)/__gcd(x, y);
		for (unt64 k = 1; k <= l; k++){
			printf("At k = %llu\n", k);
			printf("lcm(m, k) = %llu\n", (x*k) / __gcd(x, k));
			printf("lcm(n, k) = %llu\n", (y*k) / __gcd(y, k));
			if ((((x*k) / __gcd(x, k)) % y == 0) &&  (((y*k) / __gcd(y, k)) % x == 0)) {
				printf("%llu\n", k);
				break;
			}
			printf("\n");
		}
	}
	return 0;
}