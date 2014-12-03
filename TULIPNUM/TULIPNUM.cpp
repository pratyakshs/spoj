#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, q, x, y;
	scanf("%i", &t);
	for(int tt = 1; tt <= t; tt++) {
		scanf("%i %i", &n, &q);
		int pre[n+1];
		scanf("%i", &x);
		pre[0] = 0; pre[1] = 1;
		for(int i = 1; i < n; i++) {
			scanf("%i", &y);
			if (y != x)
				pre[i+1] = pre[i] + 1;
			else
				pre[i+1] = pre[i];
			x = y;
		}
		printf("Case %i:\n", tt);
		for(int i = 0; i < q; i++) {
			scanf("%i %i", &x, &y);
			if (pre[x] != pre[x-1])
				printf("%i\n", pre[y] - pre[x-1]);
			else
				printf("%i\n", pre[y] - pre[x-1] + 1);
		}
	}
	return 0;
}