#include<iostream> 
#include<string.h> 
#include<stdio.h> 
#include<algorithm> 
#include<set> 
#include<vector> 
#include<string> 
using namespace std; 

int main()
{ int t; cin>>t; 
	string tu; 
	getline(cin,tu); 
	while(t-->0) 
		{ string test; 
			vector<string> a; 
			getline(cin,test); 
			int j=0; 
			string temp; 
			a.push_back(temp); 
			for(int i=0;i<test.size();i++) 
			{ 
				if(test[i]!=' ')
				{ 
					a[j].push_back(test[i]);
					if(test[i+1]==' ' || test[i+1]==0){ 
						a.push_back(temp); j++; 
					} 
				} 
			}
			set<string> s; 
			for(int i=0;i<a.size();i++)
			{ 
				s.insert(a[i]); 
			}
			cout<<s.size()-1<<endl; 
		} 
		return 0; 
	}
	