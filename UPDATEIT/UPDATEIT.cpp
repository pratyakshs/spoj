#include <bits/stdc++.h>
using namespace std;

#define MAXN 32768

int nodes[MAXN], lb[MAXN], rb[MAXN];

void update(int node, int l, int r, int val) {
	if (l <= lb[node] && r >= rb[node]) {
		nodes[node] += val;
		return;
	}
	else if (r < lb[node] || l > rb[node])
		return;
	int n2 = 2 * node;
	if (n2 < MAXN) {
		update(n2, l, r, val);
		update(n2+1, l, r, val);
	}
}

int query(int node, int index) {
	if (index > rb[node] || index < lb[node])
		return 0;
	int n2 = 2 * node;
	if (n2 >= MAXN) 
		return nodes[node];
	if (index <= rb[n2]) 
		return nodes[node] + query(n2, index);
	if (index >= lb[n2+1])
		return nodes[node] + query(n2+1, index);
}

void init(int node, int l, int r) {
	lb[node] = l;
	rb[node] = r;
	int d = (r - l + 1) / 2, n2 = 2 * node;
	if (n2 < MAXN) {
		init(n2, l, l + d - 1);
		init(n2+1, l + d, r);
	}
}

int main() {
	init(1, 0, MAXN / 2 - 1);

	int t, n, u, l, r, val, q, x;
	scanf("%i", &t);
	for(int tt = 0; tt < t; tt++) {
		memset(nodes, 0, sizeof(nodes));
		scanf("%i %i", &n, &u);
		for(int i = 0; i < u; i++) {
			scanf("%i %i %i", &l, &r, &val);
			update(1, l, r, val);
		}
		scanf("%i", &q);
		for(int i = 0; i < q; i++) {
			scanf("%i", &x);
			printf("%i\n", query(1, x));
		}
	}
	return 0;
}

/**
 * Straightforward segment tree. 
 */
 