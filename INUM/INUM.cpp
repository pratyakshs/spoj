#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    scanf("%lli", &n);
    ll arr[n];
    for(int i=0; i<n; i++) 
        scanf("%lli", &arr[i]);
    sort(arr, arr+n);
    ll maxdiff = arr[n-1] - arr[0];
    ll minN = 0, maxN;
    if (maxdiff == 0) {
        maxN = (n*(n-1))>>1;
    }
    else {
        ll low = 0;
        for(int i=0; i<n; i++) {
            if (arr[i] == arr[0])
                low++;
            else 
                break;
        }
        ll high = 0;
        for(int i=n-1; i>=0; i--) {
            if (arr[i] == arr[n-1])
                high++;
            else
                break;
        }
        maxN = low*high;
    }
    ll mindiff = LLONG_MAX;
    for(int i=1; i<n; i++) {
        ll d = arr[i] - arr[i-1];
        if (d == mindiff) {
            minN ++;
        }
        else if (d < mindiff) {
            minN = 1;
            mindiff = d;
        }
    }
    if (mindiff == 0) {
        minN = 0;
        ll curr = 1;
        for(int i=1; i<n; i++) {
            if (arr[i] == arr[i-1]){
                curr++;
            }
            else {
                minN += (curr*(curr-1))>>1;
                curr = 1;
            }
        }
        minN += (curr*(curr-1))>>1;
    }
    printf("%lli %lli", minN, maxN);
    return 0;
}
