#include <bits/stdc++.h>
using namespace std;

int dp[33];

int solve(int n) {
	if (dp[n] != -1)
		return dp[n];
	if (n & 1)
		return dp[n] = 0;
	return dp[n] = 4 * solve(n-2) - solve(n-4);
}

int main() {
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	dp[4] = 11;
	int n;
	while(scanf("%i", &n) != EOF) {
		if (n == -1)
			break;
		printf("%i\n", solve(n));
	}
	return 0;
}

/**
 * Recurrence problem: solve by casework.
 */
