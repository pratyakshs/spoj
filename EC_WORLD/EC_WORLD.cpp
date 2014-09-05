#include<bits/stdc++.h>
using namespace std;

typedef vector<int> VI;

void buildTable(string& w, VI& t)
{
    t = VI(w.length());  
    int i = 2, j = 0;
    t[0] = -1; t[1] = 0;

    while(i < w.length())
    {
        if(w[i-1] == w[j]) { t[i] = j+1; i++; j++; }
        else if(j > 0) j = t[j];
        else { t[i] = 0; i++; }
    }
}

int KMP(string& s, string& w)
{
    int m = 0, i = 0;
    VI t;

    buildTable(w, t);  
    while(m+i < s.length())
    {
        if(w[i] == s[m+i])
        {
            i++;
            if(i == w.length()) return m;
        }
        else
        {
            m += i-t[i];
            if(i > 0) i = t[i];
        }
    }  
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.length() == s2.length()) {
            s1 = s1 + s1;
            if (KMP(s1, s2) != -1)
                printf("Si\n");
            else
                printf("No\n");
        }
        else
            printf("No\n");
    }
    return 0;
}
