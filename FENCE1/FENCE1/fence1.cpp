#include<stdio.h>
#define pi 3.14159265358979323846f
int main()
{
	int x;
	while(true){
		scanf("%i", &x);
		if(x!=0)
			printf("%.2f\n", x*x/(pi*2.0));
		else 
			break;
	}
}