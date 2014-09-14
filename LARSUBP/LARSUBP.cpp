#include<bits/stdc++.h>
using namespace std;
#define modulo 1000000007ULL
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int tt=1; tt <= t; tt++) {
        string s;
        cin >> s;
        int n = s.length();
        ull table[n+1][10];
        for(int i=0; i<10; i++)
            table[n][i] = 0;
        for(int i=n-1; i>=0; i--) {
            int curr = s[i] - '0';
            for(int j=0; j<curr; j++) {
                ull toadd = table[i+1][curr] + 1;
                table[i][j] = (table[i+1][j] + toadd) % modulo;
            }
            for(int j=curr; j<10; j++) {
                table[i][j] = table[i+1][j];
            }
        }
        cout << "Case " << tt << ": " << table[0][0] << endl;
    }
    return 0;
}
