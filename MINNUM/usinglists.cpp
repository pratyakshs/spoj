#include<stdio.h>
#include<string>
#include<iostream>
#include<list>
using namespace std;
#define getcx getchar_unlocked
typedef unsigned long long bignum;
inline void inp(list<char> &s) {
	s.clear(); char ch=getcx(); 
	while(ch!='\n') { s.push_back(ch); ch=getcx(); } 
}
struct ans{
	list<char>::iterator qstart, qend;
	char remainder;
	ans(string s1, char s2){
		quotient=s1;
		remainder=s2;
	}
};
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
ans divideby9(string num, string quotient, char remainder){
	if(num.length()==0){
	//	cout<<"lvl1"<<endl;
		return ans(quotient, remainder);
	}
	else if(num[0]=='9' && remainder=='\0'){
	//	cout<<"lvl5"<<endl;
		return divideby9(num.substr(1), quotient+"1", '0');
	}
	else if(remainder=='\0'){
		int D=(num[0]-'0')*10+(num[1]-'0');

		int Q=D/9;
		char q=Q+'0';
		int R=D%9;
		char r=R+'0';
		quotient.push_back(q);
		return divideby9(num.substr(2), quotient, r);
	}
	else{
		int D=(remainder-'0')*10+(num[0]-'0');
		int Q=D/9;
		char q=Q+'0';
		int R=D%9;
		char r=R+'0';
		quotient.push_back(q);
		return divideby9(num.substr(1), quotient, r);
	
	}
}
bignum convertToInt(string num, bignum ans){
	if(num.length()==0)
		return ans;
	return convertToInt(num.substr(1), ans*10+(num[0]-'0'));
}
int main(){
	std::ios_base::sync_with_stdio(false);
	string num;
	while(true){
		inp(num);

		if(num[0]=='-')
			break;
		if(num.length()==1){
			printf("1\n");
			continue;
		}
		if(num.length()<18){
			bignum n=convertToInt(num, 0);
			printf("%llu\n", (n/9)+((n%9)?1:0));
			continue;
		}
		ans a=divideby9(num, "", '\0');
		if(a.remainder=='0')
			cout<<a.quotient<<endl;
		else
			cout<<add1(a.quotient)<<endl;
	}
}