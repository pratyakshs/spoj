#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		stack<char> st;
		for(int i = 0; i < s.length(); i++) {
			if (s[i] == '(')
				continue;
			else if (s[i] == '*' || s[i] == '+' || s[i] == '-' || 
					 s[i] == '/' || s[i] == '^')
				st.push(s[i]);
			else if (s[i] == ')') {
				cout << st.top();
				st.pop();
			}
			else cout << s[i];
		}
		cout << endl;
	}
	return 0;
}

/**
 * Straightforward application of stack. 
 * On operator: push
 * On variable: print
 * On '(': nothing
 * On ')': pop and print
 */
