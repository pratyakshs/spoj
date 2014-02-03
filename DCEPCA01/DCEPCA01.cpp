#include<bits/stdc++.h>
using namespace std;
int main(){
	int t, n, a1, a2, r;
	scanf("%i", &t);
	while(t--){
		scanf("%i", &n);
		int carry=0, sum[n], s;
		for(int i=n-1; i>=0; i--){
			r=i%4;
			a1=4;
			if(i>2 && (r==0 || r==3)) a1=7;
			a2=4;
			if(r==2 || r==3) a2=7;
			s=a1+a2+carry;
			sum[i]=s%10;
			carry=s/10;
		}
		if(carry!=0) putchar_unlocked('0'+carry);
		for(int i=0; i<n; i++)
			putchar_unlocked('0'+sum[i]);
		putchar_unlocked('\n');

	}
	return 0;
}
