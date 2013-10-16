#include<stdio.h>
#include<string>
#include<iostream>
#include<math.h>
using namespace std;

int trans(string s1, string s2)
{
	if(s1.size()==1 || s2.size()==1)
	{
		if(s1[0]==s2[0])
			return s1.size()+s2.size()-2;
		else
			return s1.size()+s2.size()-1;
	}

	if(s1[0]==s2[0])
		return trans(s1.substr(1), s2.substr(1));
	else
		return 1+trans(s1.substr(1), s2.substr(1));
}
int main()
{	
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		string s1, s2;
		cin>>s1>>s2;
		printf("%i\n", trans(s1,s2));
	}
	return 0;
}