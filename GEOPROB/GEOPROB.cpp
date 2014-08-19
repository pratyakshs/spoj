#include<bits/stdc++.h>
using namespace std;

string mult2(string s) {
    vector<int> num;
    num.push_back(0);
    for(int i=0; i<s.length(); i++) {
        num.push_back(s[i] - '0');
    }
    int carry = 0;
    for(int i=num.size() - 1; i >= 0; i--) {
        int d = num[i] * 2 + carry;
        num[i] = d % 10;
        carry = d / 10;
    }
    string ans = "";
    for(int i=0; i<num.size(); i++){
        ans.push_back('0'+num[i]);
    }
    return ans;
}

string subtract(string a, string b) {
    int n1 = a.length(), n2 = b.length(), nd = n1 - n2;
    vector<int> numa, numb;
    for(int i=0; i<nd; i++)
        numb.push_back(0);
    for(int i=0; i<a.length(); i++)
        numa.push_back(a[i] - '0');
    for(int i=0; i<b.length(); i++)
        numb.push_back(b[i] - '0');
    vector<int> numc(n1, 0);
    for(int i=numa.size() - 1; i>=0; i--) {
        if (numa[i] >= numb[i])
            numc[i] = numa[i] - numb[i];
        else {
            numc[i] = numa[i] + 10 - numb[i];
            numb[i-1]++;
        }
    }
    string ans = "";
    for(int i=0; i<numc.size(); i++){
        ans.push_back('0'+numc[i]);
    }
    return ans;
}
int main() {
    int t;
    scanf("%i", &t);
    while(t--) {
        string b, c, d;
        cin >> b >> c >> d;
        string ans = subtract(subtract(mult2(c), b), d);
        bool flag = false;
        for(int i=0; i<ans.length(); i++) {
            if (ans[i] != '0') {
                flag = true;
            }
            if (flag) {
                printf("%c", ans[i]);
            }
        }
        printf("\n");
    }


    return 0;
}
