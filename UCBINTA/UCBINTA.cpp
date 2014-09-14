#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    int n;
    scanf("%i", &n);

    int table[n][n];
    ll sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%i", &table[i][j]);
            sum += table[i][j];
        }
    }
    sum /= 2*(n-1);
    if (n == 2) {
        printf("1 1");
        return 0;
    }

    const ll sumperm = sum;
//    cout << "sum = " << sum << endl;
    int ans[n];
    for(int i=0; i<n-2; i++) {
//        cout << "hello" << i << endl;
        ll rowsum = 0;
        for(int j=i+1; j<n; j++) {
            rowsum += table[i][j];
        }

        ans[i] = (rowsum - sum)/(n-2-i);
        sum -= ans[i];
    }

    ll temp = sumperm - table[n-1][0];
    for(int i=1; i<n-2; i++)
        temp -= ans[i];
    ans[n-2] = temp;
    ans[n-1] = sum - temp;

    for(int i=0; i<n; i++)
        printf("%i ", ans[i]);
   
    return 0;
}

