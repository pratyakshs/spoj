#include<stdio.h>

unsigned int convert(unsigned int x){
	unsigned int j=0;
	if(x&1)
		return x;
	while(x){
		j<<=1;
		j+=x&1;
		x>>=1;
	}
	return j;
}

int main(){
	unsigned int n,x;
	scanf("%u", &n);
	for(int i=0; i<n; i++){
		scanf("%u", &x);
		printf("%u\n", convert(x));
	}
}