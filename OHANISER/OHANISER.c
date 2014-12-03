#include <stdio.h>
#define MOD 1000000007

int main() {
	int t, n, i, tt;
	unsigned int p1, ans[100000];
	ans[0] = p1 = 1;
	for(i = 1; i < 100000; i++) {
		ans[i] = ((ans[i-1] << 1) + p1) % MOD;
		p1 = (p1 << 1) % MOD;
	}
	scanf("%i", &t);
	for(tt = 1; tt <= t; tt++) {
		scanf("%i", &n);
		printf("Case %i: %u\n", tt, ans[n-1]);
	}
	return 0;
}