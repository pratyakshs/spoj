#include<bits/stdc++.h>
using namespace std;
inline int readInt () {
	int result = 0;
	char ch;
	while (true) {
		ch = getchar_unlocked();
		if (ch<'0' || ch>'9') break;
		result = result*10 + (ch - '0');
	}
	return result;
}
int main(){
	int t;
	t=readInt();
	while(t--){
		int n, prev, curr, ii=0;
		scanf("%i\n", &n);
		scanf("%i ", &prev);
		char str[100001], pat[100001];
		for(int i=1; i<n; i++){
			scanf("%i ", &curr);
			if(curr>prev)
				str[i-1]='G';
			else if(curr<prev)
				str[i-1]='L';
			else str[i-1]='E';
			prev=curr;
		}
//		str[n-1]='\0';
		scanf("%s", pat);
		for(ii=0; pat[ii]!='\0'; ii++){}
//		printf("str=%s pat=%s ii=%i\n", str, pat, ii);
		int T[ii+1];
		for(int i=0; i<=ii; i++)
			T[i]=-1;
		for(int i=1; i<=ii; i++){
			int pos=T[i-1];
			while(pos!=-1 && pat[pos]!=pat[i-1]) pos=T[pos];
			T[i]=pos+1;
		}
		int sp=0, kp=0;
		bool flag=false;
		while(sp<n){
			while(kp!=-1 && (kp==ii || pat[kp]!=str[sp])) kp=T[kp];
			kp++;
			sp++;
			if(kp==ii){
				flag=true; 
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else printf("NO\n");
	}
}
				

