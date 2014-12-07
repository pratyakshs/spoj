#include <stdio.h>
int main() {
	int n;
	while(scanf("%i", &n)!=EOF)
		printf("%i\n", (n<2)?n:(2*n-2));
}