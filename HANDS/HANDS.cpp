#include<stdio.h>
#define tx 65.454545
int part(int t){
	for(int i=1; i<=23; i++){
		if(t>=(i-1)*tx && t<i*tx)
			return i;
	}
}
int main(){
	int t;
	scanf("%i", &t);
	while(t-->0){
		int hours1=0, mins1=0;
		char x;
		do{
			x=getchar_unlocked();
		}while(!(x>='0' && x<='9'));
		hours1=10*(x-'0');
		x=getchar_unlocked();
		hours1+=(x-'0');
		getchar_unlocked();
		x=getchar_unlocked();
		mins1=10*(x-'0');
		x=getchar_unlocked();
		mins1+=(x-'0');
//		printf("h1m1: %i %i\n", hours1, mins1);

		int hours2=0, mins2=0;
		do{
			x=getchar_unlocked();
		}while(!(x>='0' && x<='9'));
		hours2=10*(x-'0');
		x=getchar_unlocked();
		hours2+=(x-'0');
		getchar_unlocked();
		x=getchar_unlocked();
		mins2=10*(x-'0');
		x=getchar_unlocked();
		mins2+=(x-'0');
//		printf("h2m2: %i %i\n", hours2, mins2);
	
		int t1=hours1*60+mins1, t2=hours2*60+mins2;
		printf("%i\n", part(t2)-part(t1));
		
	}
}




