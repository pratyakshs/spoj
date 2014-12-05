#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int t, n, x, y;
	scanf("%i", &t);
	while(t--) {
		scanf("%i", &n);
		int lo[n], hi[n], bo[2*n];

		for(int i=0; i<n; i++) {
			scanf("%i %i", &lo[i], &hi[i]);
			bo[i]=lo[i];
			bo[n+i]=hi[i];
		}
		sort(bo, bo+2*n);
		int ans=0, l1, r1;
		for(int i=1; i<2*n; i++){
			int l=bo[i-1], r=bo[i], loc=0;
			for(int j=0; j<n; j++){
				if (hi[j]>=r&&lo[j]<=l)
					loc++;
			}
			if(loc>ans){
				ans=loc;
				l1=l; r1=r;
			}
		}
		printf("%i\n", ans);
		// printf("%i %i\n", l1, r1);
	}
	return 0;
}