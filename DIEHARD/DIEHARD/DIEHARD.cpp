#include<bits/stdc++.h>
using namespace std;
#define sz 3000
int table[sz][sz][3];
	
int calc(int h, int a, int pos){
//	printf("%i %i %i %i %i\n", h, a, table[6 ][6][0], table[6][6][1], table[6][6][2]);
	if(h<=0 || a<=0)
		return 0;
	if(h<sz && a<sz && table[h][a][pos]!=-1)
		return table[h][a][pos];
	int ans;
	if(pos==0)
		ans=max(calc(h-5, a-10, 1), calc(h+3, a+2, 2))+1;
	else if(pos==1)
		ans=max(calc(h+3, a+2, 2), calc(h-20, a+5, 0))+1;
	else ans=max(calc(h-20, a+5, 0), calc(h-5, a-10, 1))+1;
	if(h<sz && a<sz)
		return table[h][a][pos]=ans;
	return ans;
}
int main(){
for(int i=0; i<1050; i++){
		for(int j=0; j<1050; j++){
			table[i][j][0]=table[i][j][1]=table[i][j][2]=-1;
		}
	}
//	calc(999, 999, 0); calc(999, 999, 1); calc(999, 999, 2);
	int t;
	scanf("%i", &t);
	while(t--){
		int h, a;
		scanf("%i %i", &h, &a);
		if(h==0 || a==0)
			printf("0\n");
		else
			printf("%i\n", max(calc(h, a, 0), max(calc(h, a, 1), calc(h, a, 2)))-1);
	}
}		
