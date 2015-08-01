#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t, n;
	cin >> t;
	string s1, s2;
	int dp[2][6300];
	for(int i = 0; i < t; i++) {
		cin >> s1;
		s2 = s1;
		reverse(s1.begin(), s1.end());
		n = s1.length();
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if (s1[i-1] == s2[j-1])
					dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
				else
					dp[i%2][j] = max(dp[i%2][j-1], dp[(i-1)%2][j]);
			}
		}
		cout << n - dp[n%2][n] << endl;
	}
	return 0;
}

/**
 * Ans = len(s) - len(LCS(s, reverse(s)))
 */
