#include<bits/stdc++.h>
inline int readInt () {
	int result = 0;
	char ch;
	while (true) {
		ch = getchar_unlocked();
		if (ch<'0' || ch>'9') break;
		result = result*10 + (ch - '0');
	}
	return result;
}
int main(){
	int t;
	scanf("%i\n", &t);
	while(t--){
		int a=readInt(), b=readInt();
		int arr[a];
		for(int i=0; i<a; i++)
			arr[i]=readInt();
		int front=0, back=-1, maxSum=0, maxWindow=0, sum=arr[0];
		while(true){
			if(front>=a)
				break;
			if(sum<=b)
				sum+=arr[++front];
			else{
				if(front>back+1)
					sum-=arr[++back];
				else
					sum+=(arr[++front]-arr[++back]);
			}
			if(front<a && sum<=b && (maxWindow<front-back || (maxWindow==front-back && sum<maxSum))){
				maxSum=sum;
				maxWindow=front-back;
			}
		}
		printf("%i %i\n", maxSum, maxWindow);
	}
}
