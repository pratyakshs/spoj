#include<string>
#include<iostream>
using namespace std;
string add1(string num){
	if(num.length()==0)
		return "1";
	char last=num[num.length()-1];
	if(last!='9')
		{
			num[num.length()-1]++;
			return num;
		}
	return add1(num.substr(0, num.length()-1))+"0";
}
int main(){
	string s;
	while(cin>>s)
		cout<<add1(s)<<endl;
}