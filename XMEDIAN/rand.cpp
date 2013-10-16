#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main(){
	srand (time(NULL));
	int t;
	scanf("%i", &t);
	printf("%i\n", t);
	for(int i=0; i<t; i++){
		printf("%i\n", rand()%100);
	}
}