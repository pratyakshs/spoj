#include<stdio.h>
#include<math.h>
typedef long long bigint;

struct node{
	bigint sum;
	int i, j;

};

//void modify(int treeIndex, int i, )
int main(){
	int n;
	scanf("%i", &n);
	printf("%lf\n", ceil(log2(n)));

	node tree[1<<(int(ceil(log2(n)))+1)];


}