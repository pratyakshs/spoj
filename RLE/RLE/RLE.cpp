#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(cin>>s){
		char cur;
		int count=1;
		for(int i=1; i<s.length(); i++){
			if(s[i]==s[i-1])
				count++;
			else{
				if(count>3)
					printf("%i!%c", count, s[i-1]);
				else
					while(count--)
						printf("%c", s[i-1]);
				count=1;
			}
		}
		if(count>3)
			printf("%i!%c", count, s[s.length()-1]);
		else
			while(count--)
				printf("%c", s[s.length()-1]);
		printf("\n");
	}
	return 0;
}
