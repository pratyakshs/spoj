#include<bits/stdc++.h>
int main(){
	int t, n, num, den, cr;
	char gr;
	scanf("%i", &t);
	while(t--){
		scanf("%i", &n);
		num=den=0;
		for(int i=0; i<n; i++){
			scanf("%i %c", &cr, &gr);
			den+=cr;
			if(gr=='S')
				num+=cr*10;
			else
				num+=cr*(9-gr+'A');
		}
		double ans=num*1.0/den;
		printf("%.2lf\n", ans);
	}
	return 0;
}
