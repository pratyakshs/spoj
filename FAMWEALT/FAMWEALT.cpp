#include<bits/stdc++.h>
using namespace std;
#define SIZE 131072
double *tree;
void populate_up(int x, double w){
	tree[x]=w;
	if(x==1)
		return;
	int parent=x>>1;
	if(x&1 && parent&1)
		populate_up(parent, 4*w);
	else
		populate_up(parent, 2*w);
}
void populate_down(int x, double w){
	if(x>=SIZE)
		return;
	tree[x]=w;
	int lc=x<<1;
	double w2=w/2;
	if(x&1){
		populate_down(lc, w2);
		populate_down(lc+1, w2/2);
	}
	else{
		populate_down(lc, w2);
		populate_down(lc+1, w2);
	}
}
int main(){
	int t, x, y, w;
	scanf("%i", &t);
	while(t--){
		scanf("%i %i %i", &x, &y, &w);
		tree=new double[SIZE];
		for(int i=0; i<SIZE; i++)
			tree[i]=0;
		populate_up(x, w);
		populate_down(1, tree[1]);
		printf("%.6lf\n", tree[y]);
		delete[] tree;
	}
	return 0;
}


