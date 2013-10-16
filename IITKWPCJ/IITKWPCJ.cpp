#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		string s1, s2;
		cin>>s1>>s2;
		bool flag=true;
		int g=gcd(s1.length(), s2.length());

		for(int j=0; j<s1.length(); j++)
		{
			if(s1[j]!=s1[j%g])
			{
				flag=false;
				break;
			}	
		}
		if(flag)
		{
			for(int j=0; j<s2.length(); j++)
			{
				if(s2[j]!=s1[j%g])
				{
					flag=false;
					break;
				}	
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}