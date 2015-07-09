#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000020
int main() {
	int maxa = sqrt(MAXN), maxb = sqrt(maxa) + 1;
	vector<bool> prime(maxa, 1);
	for(int i = 2; i <= maxb; i++) {
		if (prime[i])
			for(int j = i*i; j < maxa; j += i) 
				prime[j] = 0;
	}
	int primes[3410], p = 0;
	for(int j = 2; j < maxa; j++) {
		if (prime[j]) 
			primes[p++] = j;
	}
	int t, a, b; 
	scanf("%i", &t);
	while(t--) {
		scanf("%i %i", &a, &b);
		int n = b - a + 1;
		vector<bool> isprime(n, 1);
		if (a == 1) 
			isprime[0] = 0;
		for(int i = 0; i < p; i++) {
			int pr = primes[i];
			int x = (a%pr)?a/pr+1:a/pr, y = b/pr;
			for(int j = x; j <= y; j++) {
				int m = pr * j; 
				if (m >= a && m <= b && j != 1)
					isprime[m-a] = 0; 
			}
		}
		for(int i = 0; i < n; i++) 
			if (isprime[i])
				printf("%i\n", i+a);
		printf("\n");
	}
	return 0;
}

/**
 * Find all primes till sqrt(1000000000) using 
 * simple sieve. Then sieve again in the range
 * [m, n] using these primes. Ta da!
 */
