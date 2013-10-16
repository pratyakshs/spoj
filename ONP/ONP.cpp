#include<stdio.h>
#include<stack>
#include<map>
#include<iostream>
#include<string>
using namespace std;


int main()
{
	map<char, int> m;
	m['+']=1; 
	m['-']=2;
	m['*']=3;
	m['/']=4;
	m['^']=5;
	m[')']=-1;
	m['(']=-1;
	int t;
	scanf("%i\n", &t);
	stack<char> s;
	char current;
	for(int i=0; i<t; i++)
	{
		string str;
		cin>>str;
		int k=0;
		while(1)
		{
			cout<<"here1"<<endl;
			current=str[k];
			cout<<"here2"<<endl;
			if(m[current]==0)
			{
				printf("%c", current);
			}
			else
			{
				if(m[current]!=-1)
				{
					while(!s.empty())
					{
						if((current!='^' || m[current]<m[s.top()]))
						{
							printf("%c", s.top());
							s.pop();
						}
					}
					s.push(current);
				}
				else if(current=='(')
				{
					s.push('(');
				}
				else if(current==')')
				{
					while(s.top()!='(')
					{
						printf("%c", s.top());
						s.pop();
					}
					s.pop();

				}

			};
			while(!s.empty())
			{
				printf("%c", s.top());
				s.pop();
			}
			k++;
			if(k==str.length())
			{
				cout<<"fin";	
				break;
			}	

		}
		printf("\n");
	}
}