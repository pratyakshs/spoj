#include<bits/stdc++.h>
using namespace std;
inline void getln(string &s){
	getchar_unlocked();
	s="";
	char ch=getchar_unlocked();
	while(ch!='\n'){
		s.push_back(ch);
		ch=getchar_unlocked();
	}
}
string bin(char ch){
	switch(ch){
		case ' ': return "00000";
		case 'A': return "00001";
		case 'B': return "00010";
		case 'C': return "00011";
		case 'D': return "00100";
		case 'E': return "00101";
		case 'F': return "00110";
		case 'G': return "00111";
		case 'H': return "01000";
		case 'I': return "01001";
		case 'J': return "01010";
		case 'K': return "01011";
		case 'L': return "01100";
		case 'M': return "01101";
		case 'N': return "01110";
		case 'O': return "01111";
		case 'P': return "10000";
		case 'Q': return "10001";
		case 'R': return "10010";
		case 'S': return "10011";
		case 'T': return "10100";
		case 'U': return "10101";
		case 'V': return "10110";
		case 'W': return "10111";
		case 'X': return "11000";
		case 'Y': return "11001";
		case 'Z': return "11010";
	}
}

int main(){
	int t;
	scanf("%i", &t);
	for(int ii=1; ii<=t; ii++){
		int r, c; string str;
		scanf("%i %i", &r, &c);
		getln(str);
		string code;
		for(int j=0; j<str.length(); j++){
			code+=bin(str[j]);
		}
		for(int j=code.length(); j<=r*c; j++)
			code+="0";
		char a[r][c];
		int m=r, n=c;
		int i, k = 0, l = 0, it=0;
		while (k < m && l < n){
			for (i = l; i < n; ++i)
				a[k][i]=code[it++];
			k++;
			for (i = k; i < m; ++i)
				a[i][n-1]=code[it++];
			n--;
			if ( k < m){
				for (i = n-1; i >= l; --i)
					a[m-1][i]=code[it++];
				m--;
			}
			if (l < n){
				for (i = m-1; i >= k; --i)
					a[i][l]=code[it++];
				l++;   
			}       
		}
		printf("%i ", ii);
		for(int ji=0; ji<r; ji++)
			for(int jj=0; jj<c; jj++)
				printf("%c", a[ji][jj]);
		printf("\n");

	}
	return 0;
}
