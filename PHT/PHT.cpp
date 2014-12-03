#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t;
	scanf("%i", &t);
	for(int tt = 1; tt <= t; tt++){
		ll k;
		scanf("%lli", &k);
		double s = sqrt(k+1) - 1;
		int c = s; ll c1;
		for(int i = -2; i <= 2; i++) {
			c1 = c + i;
			ll k1 = c1 * (c1 + 2);
			if (k1 > k)
				break;
		}
		printf("Case %i: %lli\n", tt, c1-1)	;
	}
}