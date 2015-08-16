#include <bits/stdc++.h>
using namespace std;

int main() {
	int A[10010], B[10010];
	int t, n, u, l, r, val, q, x = 0;
	
	scanf("%i", &t);
	for(int tt = 0; tt < t; tt++) {
		scanf("%i %i", &n, &u);
		memset(B, 0, sizeof(B));
		x = 0;
		for(int  i = 0; i < u; i++) {
			scanf("%i %i %i", &l, &r, &val);
			B[l] += val;
			B[r+1] -= val;
		}
		for(int i = 0; i < n; i++) {
			x += B[i];
			A[i] = x;
		}
		scanf("%u", &q);
		for(int i = 0; i < q; i++) {
			scanf("%i", &x);
			printf("%i\n", A[x]);
		}
	}
	return 0;
}

/**
 * Linear time solution - no segment tree required. 
 */
 