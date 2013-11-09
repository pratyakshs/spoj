#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

int height(string s){
	if(s[0]=='l')
		return 0;
	int leafCount=0, nodeCount=0, i;
	for(i=1; i<s.length(); i++){
		if(s[i]=='n')
			nodeCount++;
		else
			leafCount++;
		if(leafCount>nodeCount)
			break;
	}
		
	string left=s.substr(1, i);
	string right=s.substr(i+1);
	return max(height(left), height(right))+1;
}
int main(){
	int t;
	cin>>t;	
	while(t-->0){
		string s;
		cin>>s;
		cout<<height(s)<<endl;
	}
	return 0;
}

