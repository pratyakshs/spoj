#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline unsigned int nlpo2(register unsigned int x) {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return (x + 1);
}

inline unsigned int h(register unsigned int x) {
    if (x && ((x & (x - 1)) == 0)) { // if power of two
        return x;
    }
    return nlpo2(x);
}

inline unsigned int lg2(register unsigned int x){
	int ans = 0;
	x = h(x);
	while (x >>= 1) ++ans;
	return ans;
}

int main() {
	ll t, arr[3];
	scanf("%lli", &t);
	for(int tt=1; tt<=t; tt++){
		scanf("%lli %lli %lli", &arr[0], &arr[1], &arr[2]);
		sort(arr, arr+3);
		ll a2 = (ll)lg2(arr[0]) + (ll)lg2(arr[1]) + (ll)lg2(arr[2]);
		// printf("%lli\n", lg2(arr[2]));
		printf("Case #%i: %lli %lli\n", tt, arr[0]-1+arr[0]*(arr[1]-1+arr[1]*(arr[2]-1)), a2);
	}
	return 0;
}