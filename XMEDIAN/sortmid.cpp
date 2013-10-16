#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int t;
	scanf("%i", &t);
	vector<int> v(t);
	for(int i=0; i<t; i++){
		scanf("%i", &v[i]);
	}
	for(int i=1; i<=t; i++){
		sort(v.begin(), v.begin()+i);
		printf("%i\n", v[i/2]);
	}
}