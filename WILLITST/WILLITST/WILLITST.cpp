#include<stdio.h>
#include<math.h>
using namespace std;
typedef unsigned long long bignum;

int main(){
	bignum n;

	scanf("%llu", &n);
	if(log2(n)==int(log2(n)))
		printf("TAK");
	else
		printf("NIE");
	return 0;
}

