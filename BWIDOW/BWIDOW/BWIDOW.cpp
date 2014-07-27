#include<stdio.h>

int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		int n;
		scanf("%i", &n);
		int r[n], R[n], mr=0, index=0;
		for(int i=0; i<n; i++){
			scanf("%i %i", &r[i], &R[i]);
			if(r[i]>mr){
				mr=r[i];
				index=i+1;
			}
		}
		bool flag=true;
		for(int i=0; i<n; i++){
			if(R[i] >= mr && i!=index-1){
				printf("-1\n");
				flag=false;
				break;
			}
		}
		if(flag)
			printf("%i\n", index);
	}
}
		
