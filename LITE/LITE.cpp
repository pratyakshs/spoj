#include <bits/stdc++.h>
#define depth 18
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
using namespace std;
int ctr = 0;
struct node {
	int on, off, upd, l, r;
	node() {
		on = off = upd = l = r = 0;
	}
} tree[1 << depth];

int offset = (1 << (depth - 1)) - 1, num_leaves = offset + 1, total_nodes = offset + num_leaves;

inline void flip(int &x) {
	if (x == 1)
		x = 0;
	else
		x = 1;
}

inline int level(int v) {
	int ans = 0;
	while(v >= (1 << ans)){
		ans++;
	}
	return ans;
}

inline int calc_l(int v){
	while(v <= offset) {
		v <<= 1;
	}
	return v;
}

inline int calc_r(int v){
	while(v <= offset) {
		v <<= 1;
		v++;
	}
	return v;
}

void init(int v) {
	if (v > offset) {
		tree[v].off = 1;
		tree[v].l = tree[v].r = v-offset;
	}
	else {
		tree[v].off = num_leaves >> (level(v) - 1);
		tree[v].l = calc_l(v)-offset;
		tree[v].r = calc_r(v)-offset;
		init(v << 1);
		init(1+(v << 1));
	}
}

void toggle(int v, int l, int r){
	// cout << ++ctr << " toggle(" << v << ", " << l << ", " << r << ")\n";
	// cout << "tree[v].l = " << tree[v].l << ", tree[v].r = " << tree[v].r << endl;
	int left = v << 1, right = left + 1, mid = (tree[v].l + tree[v].r) >> 1;

	if (tree[v].upd){
		SWAP(tree[v].on, tree[v].off);
		tree[v].upd = 0;
		if (left < total_nodes) {
			flip(tree[left].upd);
			flip(tree[right].upd);
		}
	}

	if (r < tree[v].l || l > tree[v].r)
		return;
	
	if (l <= tree[v].l && r >= tree[v].r) {
		SWAP(tree[v].on, tree[v].off);
		if (left < total_nodes) {
			flip(tree[left].upd);
			flip(tree[right].upd);
		}
		return;
	}

	if (l > mid) {
		// cout << "case1\n";
		toggle(right, l, r);
	}
	else if (r <= mid) {
		// cout << "case2\n";
		toggle(left, l, r);
	}
	else{
		// cout << "case3\n";
		toggle(left, l, r);
		toggle(right, l, r);
	}

	int lon, loff, ron, roff;
	if (tree[left].upd == 0) {
		lon = tree[left].on;
		loff = tree[left].off;
	}
	else{
		lon = tree[left].off;
		loff = tree[left].on;
	}
	if (tree[right].upd == 0) {
		ron = tree[right].on;
		roff = tree[right].off;
	}
	else{
		ron = tree[right].off;
		roff = tree[right].on;
	}

	tree[v].on = lon + ron;
	tree[v].off = loff + roff;
	
	return;

}

int count1(int v, int l, int r) {

	int left = v << 1, right = left + 1, mid = (tree[v].l + tree[v].r) >> 1;

	if (tree[v].upd){
		SWAP(tree[v].on, tree[v].off);
		tree[v].upd = 0;
		if (left < total_nodes) {
			flip(tree[left].upd);
			flip(tree[right].upd);
		}
	}


	if (r < tree[v].l || l > tree[v].r)
		return 0;

	if (v > offset && tree[v].l >= l && tree[v].r <= r){
		return tree[v].on;
	}

	if (l <= tree[v].l && r >= tree[v].r) {
		return tree[v].on;
	}

	if (l > mid) {
		return count1(right, l, r);
	}
	else if (r <= mid) {
		return count1(left, l, r);
	}
	else{
		return count1(left, l, r) + count1(right, l, r);
	}


}

void print(){
	for(int i=1; i<=total_nodes; i++){
		printf("%i ", i);
	}
	printf("\n");
	for(int i=1; i<=total_nodes; i++){
		printf("--");
	}
	printf("\n");
	for(int i=1; i<=total_nodes; i++){
		printf("%i ", tree[i].on);
	}
	printf("\n");
	for(int i=1; i<=total_nodes; i++){
		printf("%i ", tree[i].off);
	}
	printf("\n");
	for(int i=1; i<=total_nodes; i++){
		printf("%i ", tree[i].upd);
	}
	printf("\n");
	for(int i=1; i<=total_nodes; i++){
		printf("--");
	}
	printf("\n");
	for(int i=1; i<=total_nodes; i++){
		printf("%i ", i);
	}
	printf("\n\n");
}

int main() {
	init(1);
	int n, m, op, l, r;
	scanf("%i %i", &n, &m);

	for(int i = 0; i < m; i++) {
		scanf("%i %i %i", &op, &l, &r);
		if (op == 0)
			toggle(1, l, r);
		else
			printf("%i\n", count1(1, l, r));
		// print();
	}
	return 0;
}
