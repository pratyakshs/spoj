//O(n) solution. AC.
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		int n;
		scanf("%i",&n);
		float x, nearest0=2, f2=0, max0_5=0, min1=2;
		bool flag=false;
		for(int j=0; j<n; j++){
			scanf("%f", &x);
			if(!flag){
				if(x>=1){
					if((x+nearest0)<2)
						flag=true;
					if(x<min1)
						min1=x;
				}
				else if(x<=0.5){
					if(x>max0_5)
						max0_5=x;
					if(nearest0>x)
						nearest0=x;
					if(min1+x<2)
						flag=true;
				}
				else {
					if(f2==1 || (x+max0_5>1))
						flag=true;
					else {
						f2++;
						if(nearest0>x)
							nearest0=x;
					}	
				}
			}
		}
		if(flag)
			printf("found\n");
		else 
			printf("not found\n");
	}
}
