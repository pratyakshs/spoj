#include<stdio.h>

int main(){
	int i=0, curr=0, w=0, r, bo, bl;
	int scores[]={0,0,0};
	while(i<6 && w<2){
		char c;
		scanf("%c ", &c);
		if(c=='O'){
			w++;
			bo=curr;
			bl=(curr)?0:1;
			curr=2;
			i++;
		}
		else if(c=='N' || c=='W')
			continue;
		else{
			r=c-48;
			scores[curr]+=r;
			if(r%2){
				if(w==0){
					if(curr==0)
						curr=1;
					else
						curr=0;
				}
				else{
					if(curr==2)
						curr=bl;
					else
						curr=2;
				}
			}
			i++;
		}
	}
	printf("%i\n%i\n%i\n", scores[0], scores[1], scores[2]);
}