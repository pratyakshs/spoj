#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

inline void inp(string &s){
	s=""; char ch=getchar_unlocked();
	while(ch!='\n'){s+=ch; ch=getchar_unlocked();}
}

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	int j=1, count=0;
	bool state=true;
	while(cin>>s){
		count=0; state=true;
		for(int i=0; i<s.length(); i++){
			if(state){
				if(s[i]=='1'){
					count++;
					state=false;
				}
			}
			else{
				if(s[i]=='0'){
					count++;
					state=true;
				}
			}
		
		}
		printf("Game #%i: %i\n", j++, count);
	}
}
