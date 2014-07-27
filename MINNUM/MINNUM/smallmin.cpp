#include<stdio.h>

int main(){
	int t;
	while(scanf("%i", &t)!=EOF){
		if(t==-1)
			break;
		printf("%i\n", (t/9)+((t%9)?1:0));
	}
}
