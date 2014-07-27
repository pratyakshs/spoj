#include<stdio.h>

int sumdig(int n){
	int sum = 0;
	while(n>0){
		sum = sum + (n%10);
		n = n / 10;
	}
	return sum;
}
bool ar[1000000];
int main(){
	for(int i = 0; i < 1000000; i++){
		ar[i] = false;
	}
	for(int i=0; i<1000000; i++){
		int s = sumdig(i);
		if(i + s < 1000000)
			ar[i+s]=true;
	}
	for(int i = 0; i < 1000000; i++){
		if(ar[i]==false)
			printf("%i\n", i);
	}
}