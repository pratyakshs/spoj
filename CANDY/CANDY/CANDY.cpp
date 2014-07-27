#include<stdio.h>
inline int abs(int x){
	return (x<0)?(-x):x;
}
int main(){
	while(true){
		int n, x, sum=0;
		scanf("%i", &n);
		if(n==-1)
			break;
		int arr[n];
		for(int i=0; i<n; i++){
			scanf("%i", &arr[i]);
			sum+=arr[i];
		}
		double mean=sum*1.0/n;
		int dev=0;
		if(mean==int(mean)){
			for(int i=0; i<n; i++){
				dev+=abs(arr[i]-mean);
			}
			printf("%i\n", dev/2);
		}
		else
			printf("-1\n");
	}
}
