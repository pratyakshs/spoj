#include<bits/stdc++.h>
#define minval -100000000000000LL
#define maxval 100000000000000LL
using namespace std;

typedef long long bigint;
int t, n;
bigint *pos, *neg;
bigint *table;

bigint calc(int i, int j){
	if (j-i == 1)
		return table[i] = max(pos[i]-neg[j], pos[j]-neg[i]);
	if (i==j)
		return table[i] = pos[i];
	if (i > j)
		return minval;
	if(table[i] != maxval)
		return table[i];
	return table[i] = max(pos[i]-neg[i+1]+calc(i+2,j), -neg[i]+calc(i+1,j));
}
int main() {
    scanf("%i", &t);
    while(t--) {
    	scanf("%i", &n);
    	table = new bigint[n]; 
    	for(int i=0; i<n; i++)
    		table[i] = maxval;
    	pos = new bigint[n]; neg = new bigint[n];
    	for(int i=0; i<n; i++)
    		scanf("%lli", &pos[i]);
    	for(int i=0; i<n; i++)
    		scanf("%lli", &neg[i]);
    	bigint pos1 = -neg[0]+calc(1, n-1);
    	for(int i=0; i<n; i++)
    		table[i] = maxval;
    	bigint pos2 = pos[0]-neg[n-1]-neg[1]+calc(2, n-2);
    	bigint ans = max(pos1, pos2);
    	printf("%lli\n", ans);
    	delete[] neg;
    	delete[] pos;
    	delete[] table;
    }
    return 0;
}