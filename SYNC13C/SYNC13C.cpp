#include<bits/stdc++.h>
int main(){
	int t, a, b;
	scanf("%i", &t);
	while(t--){
		scanf("%i %i", &a, &b);
		if(a%2==1 && b%2==1) printf("Ramesh\n");
		else printf("Suresh\n");
	}
	return 0;
}	
