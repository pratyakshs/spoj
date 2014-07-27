#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		long long n, m, d;
		scanf("%lli %lli", &n, &m);
		d = (m-n)%4;
		switch(d){
			case 0: printf("1\n");
					break;
			case 1: printf("3\n");
					break;
			case 2: printf("9\n");
					break;
			case 3: printf("7\n");
					break;
		}
	}
	return 0;
}
