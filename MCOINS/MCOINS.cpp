#include<stdio.h>

int *table=new int[1000001];
int main(){
	int k, l, m, n;
	scanf("%i %i %i", &k, &l, &m);
	table[1]=1;
	table[0]=-1;
	for(int i=2; i<1000001; i++){
		table[i]=-table[i-1];
if(i>=k && table[i-k]==-1) table[i]=1;
if(i>=l && table[i-l]==-1) table[i]=1;
	}
	for(int i=0; i<m; i++){
		scanf("%i", &n);
		if(table[n]==1)
			printf("A");
		else printf("B");
	}
printf("\n");
	return 0;
}


