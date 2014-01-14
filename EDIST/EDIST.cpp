#include<bits/stdc++.h>
using namespace std;
inline int mymin(int a, int b, int c){
	if(a<=b){
		if(c<=a)
			return c;
		else return a;
	}
	else{
		if(c<=b)
			return c;
		else
			return b;
	}
}

int main()
{	
	int t;
	string s1, s2;
	scanf("%i\n", &t);
	while(t--){
		cin>>s1>>s2;
		int l1=s1.length(), l2=s2.length();
		int **table=new int*[l1+1];
		for(int i=0; i<=l1; i++) table[i]=new int[l2+1];
		for(int i=0; i<=l1; i++)
			for(int j=0; j<=l2; j++)
				table[i][j]=0;
		table[0][0]=0;
		for(int i=1; i<=l1; i++) table[i][0]=i;
		for(int j=1; j<=l2; j++) table[0][j]=j;
		for(int i=1; i<=l1; i++)
			for(int j=1; j<=l2; j++)
				table[i][j]=mymin(table[i-1][j-1]+((s1[i-1]==s2[j-1])?0:1), table[i-1][j]+1, table[i][j-1]+1);
		printf("%i\n", table[l1][l2]);
		for(int i=0; i<=l1; i++) delete[] table[i];
		delete[] table;
	}
	return 0;
}
