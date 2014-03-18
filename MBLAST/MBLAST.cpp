#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1, s2;
	int k;
	cin>>s1>>s2>>k;
	int n1=s1.length(), n2=s2.length(), **table = new int*[n1+1];
	for(int i=0; i<n1+1; i++)
		table[i] = new int[n2+1];
	table[n1][n2] = 0;
	for(int i=0; i<n1; i++)
		table[i][n2] = (n1-i)*k;
	for(int i=0; i<n2; i++)
		table[n1][i] = (n2-i)*k;
	for(int i=n1-1; i>=0; i--)
		for(int j=n2-1; j>=0; j--)
			table[i][j] = min(abs(int(s1[i]) - int(s2[j])) + table[i+1][j+1], min(k+ table[i+1][j], k+table[i][j+1])); 
	cout<<table[0][0];
	return 0;
}

