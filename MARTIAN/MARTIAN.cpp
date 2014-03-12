#include<bits/stdc++.h>
typedef unsigned long long bignum;
using namespace std;
int main() {
	int m, n;
	while (scanf("%i %i", &m, &n) != EOF) {
		if (m == 0 || n == 0) 
			break;

		bignum A[m][n], B[m][n], xsums[m][n], ysums[m][n], dp[m][n];
		for (int i = 0; i < m; i++) 
			for (int j = 0; j < n; j++) 
				scanf("%llu", &A[i][j]);

		for (int i = 0; i < m; i++) 
			for (int j = 0; j < n; j++) 
				scanf("%llu", &B[i][j]);

		for (int i = 0; i < m; i++)
			xsums[i][0] = A[i][0];


		for (int i = 0; i < m; i++)
			for (int j = 1; j < n; j++)
				xsums[i][j] = xsums[i][j-1] + A[i][j];
		for (int j = 0; j < n; j++)
			ysums[0][j] = B[0][j];
		for (int i = 1; i < m; i++)
			for (int j = 0; j < n; j++)
				ysums[i][j] = ysums[i-1][j] + B[i][j];

		dp[0][0] = (A[0][0] > B[0][0]) ? A[0][0] : B[0][0];

		for (int j = 1; j < n; j++) {
			bignum mx = xsums[0][j], ys = 0;
			for (int k = j; k >= 1; k--) {
				mx = max (mx, dp[0][k-1] + ys + ysums[0][k]);
				ys = ys + ysums[0][k];
			}
			ys += ysums[0][0];
			dp[0][j] = max (mx, ys);
		}

		for (int i = 1; i < m; i++) {
			bignum mx = ysums[i][0], xs = 0;
			for (int k = i; k >= 1; k--) {
				mx = max (mx, dp[k-1][0] + xs + xsums[k][0]);
				xs = xs + xsums[k][0];
			}
			xs += xsums[0][0];
			dp[i][0] = max (mx, xs);
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				bignum mx = 0, xs = 0;
				//				for (int k = i; k >= 0; k--) {
				//					mx = max (mx, dp[k][j-1] + ysums[k][j] + xs);
				//					xs = xs + xsums[k][j];
				//				}
				//				dp[i][j] = max (mx, xs);
				dp[i][j] = max (max (dp[i-1][j-1] + ysums[i][j] + xsums[i][j-1], dp[i-1][j-1] + ysums[i-1][j] + xsums[i][j]), max (dp[i-1][j] + xsums[i][j], dp[i][j-1] + ysums[i][j]));

			}
			//			printf("\n");
		}
		//		printf("\n");
		//		printf("%llu\n", dp[m-1][n-1]);
		//		for (int i = 0; i < m; i++) {
		//			for (int j = 0; j < n; j++)
		//				printf("%llu ", dp[i][j]);
		//			printf("\n");
		printf("%llu\n", dp[m-1][n-1]);


	}
	return 0;
	}



