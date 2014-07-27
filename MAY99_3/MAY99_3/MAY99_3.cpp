#include<stdio.h>
int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}
int main(){
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		int x, y, z;
		scanf("%i %i %i", &x, &y, &z);
		if(z>x && z>y)
			printf("NO\n");
		else{
			int g=gcd(x,y);
			if(z%g==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}