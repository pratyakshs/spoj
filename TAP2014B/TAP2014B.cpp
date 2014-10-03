#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	scanf("%i", &t);
	while(t--){
		scanf("%i", &n);
		vector<int> base3;
		while(n){
			base3.push_back(n % 3);
			n /= 3;
		}

		base3.push_back(0);
		for(int i = 0; i < base3.size(); i++) {
			if (base3[i] == 2) {
				base3[i] = -1;
				base3[i+1]++;
			}
			else if (base3[i] == 3) {
				base3[i] = 0;
				base3[i+1]++;
			}
		}

		bool flag = false;
		for(int i = base3.size() - 1; i >= 0; i--) {
			if (base3[i] != 0) {
				flag = true;
				if (base3[i] == 1) 
					printf("+");
				else if (base3[i] == -1)
					printf("-");
			}
			else if (flag) 
				printf("0");
		}
		printf("\n");
	}	
	return 0;
}