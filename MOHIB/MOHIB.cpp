#include <bits/stdc++.h>
using namespace std;
typedef long long ll_t;

int main() {
	int t;
	scanf("%i", &t);
	while(t--) {
		ll_t x, a;
		scanf("%lli %lli", &x, &a);
		ll_t n = a - x, s = n * (a + 1);
		ll_t y = s - ((n * (n - 1)) / 2);
		if (y >= n - 1) 
			printf("%lli\n", y);
		else
			printf("%lli\n", n-1);
	}
	return 0;
}