#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%i", &t);
    while(t--) {
        double x;
        cin >> x;
        x = x * 100000.0;
        long long num = 0;
        if (abs(int(x) - x) < 0.000001)
            num = int(x);
        else if (abs(int(x) + 1 - x) < 0.000001)
            num = int(x) + 1;
        else if (abs(int(x) - 1 - x) < 0.000001)
            num = int(x) - 1;
        else if (abs(int(x) + 2 - x) < 0.000001)
            num = int(x) + 2;
        else if (abs(int(x) - 2 - x) < 0.000001)
            num = int(x) - 2;

        long long g = __gcd(num, 100000LL);
        cout << 100000/g << endl;
    }
}
