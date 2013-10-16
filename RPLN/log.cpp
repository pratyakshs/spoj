#include<stdio.h>
#include<math.h>

using namespace std;
int lg2(int v){


	v--;
v |= v >> 1;  //take care of 2-bit word
v |= v >> 2;  //take care of 4-bit word
v |= v >> 4;  //take care of 8-bit word
v |= v >> 8;  //take care of 16-bit word
v |= v >> 16; //take care of 32-bit word
v++;
return v;
}
int main(){
	int n;
	scanf("%i", &n);
	printf("%i\n", 1+(lg2(n)<<1));
	printf("%i\n", 1+(1<<(int(floor(log2(n)))+1)+1));
}