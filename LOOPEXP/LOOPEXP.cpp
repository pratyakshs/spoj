#include<bits/stdc++.h>
using namespace std;

int main(){
	double arr[100001];
	arr[0]=0;
	for(int i=1; i<=100000; i++)
		arr[i]=arr[i-1]+1.0/i;
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		int n;
		scanf("%i", &n);
		printf("%lf\n", arr[n]);
	}
}


