#include<bits/stdc++.h>
using namespace std;

int main() {
	int n = 100000, m = 100000;
	cout << n << " " << m << "\n";
	srand(time(NULL));
	for(int i=0; i<m; i++){
		int l = 1+(rand() % n), r = 1+(rand() % n);
		cout << rand()%2 << " " << min(l,r) << " " << max(l, r) << endl;
	}
	return 0;
}