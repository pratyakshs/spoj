#include<bits/stdc++.h>
using namespace std;
inline void inp(string &s){
	s="";
	char ch=getchar_unlocked();
	while((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
		s.push_back(ch);
		ch=getchar_unlocked();
	}
}
int main(){
	string s;
	while(true){
		inp(s);
		if(s.length()==0)
			break;
		int l[]={0, 0};
		for(int i=0; i<s.length(); i++){
			if(s[i]>='a' && s[i]<='z'){
				l[i%2]++;
			}
		}
//		printf("leven=%i lodd=%i\n", l[0], l[1]);
		int c1=((s.length()+1)/2)-l[0]+l[1];
		int c2=(s.length()/2)-l[1]+l[0];
		if(c1<c2)
			printf("%i\n", c1);
		else printf("%i\n", c2);
	}
}	
				
