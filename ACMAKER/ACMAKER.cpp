#include <bits/stdc++.h>
using namespace std;

inline isup(string &s) {
	for(int i = 0; i < s.length(); i++) 
		if (islower(s[i]))
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	while(true) {
		cin >> n;
		if (n == 0)
			break;
		set<string> insig;
		string s;
		while(n--) {
			cin >> s;
			insig.insert(s);
		}
		while(true) {
			
		}
	}
	return 0;
}