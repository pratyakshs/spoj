#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, h, w, tiles[110][110], ans;
	scanf("%i", &t);
	while(t--) {
		scanf("%i %i", &h, &w);
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) 
				scanf("%i", &tiles[i][j]);
		}
		ans = 0;
		if (w == 1) {
			for(int i = 0; i < h; i++)
				ans += tiles[i][0];
			printf("%i\n", ans);
			continue;
		}
		for(int i = 1; i < h; i++) {
			tiles[i][0] += max(tiles[i-1][0], tiles[i-1][1]);
			for(int j = 1; j < w-1; j++) {
				tiles[i][j] += max(tiles[i-1][j], 
								   max(tiles[i-1][j-1], tiles[i-1][j+1]));
			}
			tiles[i][w-1] += max(tiles[i-1][w-1], tiles[i-1][w-2]);
		}
		for(int i = 0; i < w; i++) {
			ans = max(ans, tiles[h-1][i]);
		}
		printf("%i\n", ans);
	}
	return 0;
}

/**
 * Easy DP.
 */
