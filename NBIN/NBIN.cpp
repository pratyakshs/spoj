#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll memo_sum[82];
	memo_sum[0] = 2; memo_sum[1] = 3;

	for(int i=2; i<82; i++){
		memo_sum[i] = memo_sum[i-1] + memo_sum[i-2];
	}

	int t;
	scanf("%i", &t);
	while(t--){
		ll n;
		scanf("%lli", &n);
		n++;
		ll *it = lower_bound(memo_sum, memo_sum+82, n);
		int len = (it - memo_sum) + 1, i = 2;
		char ans[len+1];
		ans[0] = '1'; ans[1] = '0';
		ans[len] = '\0';
		ll curr = n - *(it-1);
		while (i < len) {
			it = lower_bound(memo_sum, memo_sum+82, curr);
			int len2 = (it - memo_sum) + 1;
			for (; i + len2 < len; i++) {
				ans[i] = '0';
			}
			if (curr == 1) {
				ans[i] = '0';
			}
			else if (curr == 2) {
				ans[i] = '1';
			}
			else {
				ans[i] = '1';
				if (i+1 < len)
					ans[i+1] = '0';
			}
			i += 2;
			curr = curr - *(it - 1);
		}
		printf("%s\n", ans);

	}
	return 0;
}