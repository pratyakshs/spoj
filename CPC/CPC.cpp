#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	long long n;
	while(cin >> s1 >> s2 >> n) {
		if (s1 == "*")
			break;
		bool legal = true;
		if (s2[3] >= '0' && s2[3] <= '9' && s2[4] >= '0' && s2[4] <= '9') {
			if (s1[3] >= 'A')
				cout << "N" << endl;
			else {
				long long z1, z2, q1 = 0, q2 = 0, r1 = 0, r2 = 0;
				for (int i = 0; i < 3; i++) {
					q1 *= 26; 
					q1 += (s1[i] - 'A');
					q2 *= 26;
					q2 += (s2[i] - 'A');
				}
				for (int i = 3; i < 7; i++) {
					r1 *= 10;
					r1 += (s1[i] - '0');
					r2 *= 10;
					r2 += (s2[i] - '0');
				}
				if (s1 >= s2) 
					cout << "N" << endl;
				else {
					if (q2 * 10000 + r2 - (q1 * 10000) - r1 <= n) 
						cout << "Y" << endl;
					else 
						cout << "N" << endl;
				}
			}
		}
		else if (s2[3] >= 'A' && s2[3] <= 'Z' && s2[4] >= 'A' && s2[4] <= 'Z') {
			for (int i = 0; i < 5; i++) 
				if (s2[i] == 'A' || s2[i] == 'C' || s2[i] == 'I' || s2[i] == 'M'
					|| s2[i] == 'P')
					legal = false;
			if (!legal)
				cout << 'N' << endl;
			else {
				if (s1[3] >= '0' && s1[3] <= '9') {
					for(int i = 0; i < 5; i++) {
						if (s2[i] > 'P')
								s2[i]--;
						if (s2[i] > 'M')
							s2[i]--;
						if (s2[i] > 'I')
							s2[i]--;
						if (s2[i] > 'C')
							s2[i]--;
						if (s2[i] > 'A')
							s2[i]--;
					}
					long long z2 = 0, q2 = 0, r2 = 0;
					for(int i = 0; i < 5; i++) {
						q2 *= 21;
						q2 += (s2[i] - 'A');
					}
					for(int i = 5; i < 7; i++) {
						r2 *= 10;
						r2 += (s2[i] - '0');
					}
					z2 = q2 * 100 + r2;
					long long z1 = 0, q1 = 0, r1 = 0;
					for(int i = 0; i < 3; i++) {
						q1 *= 26;
						q1 += (s1[i] - 'A');
					}
					for(int i = 3; i < 7; i++) {
						r1 *= 10;
						r1 += (s1[i] - '0');
					}
					z1 = q1 * 10000 + r1;
					if (26*26*26*10000 - z1 + z2 <= n)
						cout << "Y" << endl;
					else
						cout << "N" << endl; 
				}
				else {
					if (s1 >= s2)
						cout << 'N' << endl;
					else {
						int c = 0;
						for(int i = 0; i < 5; i++) {
							if (s1[i] > 'P')
								s1[i]--;
							if (s1[i] > 'M')
								s1[i]--;
							if (s1[i] > 'I')
								s1[i]--;
							if (s1[i] > 'C')
								s1[i]--;
							if (s1[i] > 'A')
								s1[i]--;
							if (s2[i] > 'P')
								s2[i]--;
							if (s2[i] > 'M')
								s2[i]--;
							if (s2[i] > 'I')
								s2[i]--;
							if (s2[i] > 'C')
								s2[i]--;
							if (s2[i] > 'A')
								s2[i]--;
						}
						long long q1 = 0, q2 = 0;
						for(int i = 0; i < 5; i++) {
							q1 *= 21;
							q1 += (s1[i] - 'A');
							q2 *= 21;
							q2 += (s2[i] - 'A');
						}
						long long r1 = 0, r2 = 0;
						for(int i = 5; i < 7; i++) {
							r1 *= 10;
							r1 += (s1[i] - '0');
							r2 *= 10;
							r2 += (s2[i] - '0');
						}
						if (q2 * 100 + r2 - (q1 * 100) - r1 <= n)
							cout << 'Y' << endl;
						else 
							cout << 'N' << endl;
					}
				}
			}	
		}
		else {
			cout << 'N' << endl;
		}
	}
	return 0;
}