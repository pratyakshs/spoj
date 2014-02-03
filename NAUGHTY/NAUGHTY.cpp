#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, x, y;
	scanf("%i", &n);
	int *topcount=new int[100001], *bottomcount=new int[100001];
	for(int i=0; i<n; i++) {
		scanf("%i %i", &x, &y);
		topcount[x]++;
		bottomcount[y]++;
	}
	int maxtop=0, m=(n+1)>>1;
	for(int i=0; i<100001; i++){
		if(topcount[i]+bottomcount[i]<m)
			continue;
		maxtop=(topcount[i]>maxtop)?topcount[i]:maxtop;
	}
	if(maxtop)
		printf("%i\n", (0>(m-maxtop))?0:(m-maxtop));
	else
		printf("Impossible\n");
	delete[] topcount; delete[] bottomcount;
	return 0;
}

