#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int ans[1001];
	for(int i=0; i<1001; i++)
		ans[i]=0;
	ans[0]=0;
	ans[1]=1;
	ans[2]=2;
	for(int i=2; i<1001; i++){
		double s=sqrt(i);
		int m=10000000;
		for(int j=1; j<=s; j++){
			m=min(m, ans[i-j*j]);
		}
		ans[i]=m+1;
	}	
	int t;
	scanf("%i", &t);
	while(t--){
		int x;
		scanf("%i", &x);
		printf("%i\n", ans[x]);
	}
}
