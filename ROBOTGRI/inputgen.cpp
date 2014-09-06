#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 1000;
    cout << n << endl;
    srand(time(NULL));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x = rand() % 2;
            if (x)
                cout << ".";
            else
                cout << "#";
        }
        cout << endl;
    }
}
