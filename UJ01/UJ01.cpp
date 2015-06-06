#include <bits/stdc++.h>
using namespace std;

typedef long long ll_t;
int main() {
	int t;
	scanf("%i", &t);
	while(t--) {
		ll_t a, b, n;
		scanf("%lli %lli %lli", &a, &b, &n);
		ll_t l = a * b / __gcd(a, b), c = (n * l) / ((l / a) + (l / b) - 1);
		ll_t x[4] = {(c/a)*a, (c/a)*a+a, (c/b)*b, (c/b)*b+b};
		for (int i = 0; i < 4; i++) {
			if (x[i]/a + x[i]/b - x[i]/l == n) {
				printf("%lli\n", x[i]);
				break;
			}
		}
	}
}