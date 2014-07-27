//O(nlogn) sort + O(nlogn) binary search. TLE.
#include<bits/stdc++.h>
using namespace std;
double *arr;
double low, high;
int i;
inline bool bsearch(int first, int last){
	while(first<last){
		int mid=(first+last)>>1;
		if(arr[mid]>low && arr[mid]<high){
			if(mid!=i)
				return true;
			else 
				return bsearch(first, mid-1)||bsearch(mid+1, last);
		}
		else if(arr[mid]>high)
			last=mid-1;
		else
			first=mid+1;
	}
	return false;
}
//<low, >high
int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		int n;
		scanf("%i", &n);
		arr=new double[n];
		for(i=0; i<n; i++)
			scanf("%lf", &arr[i]);
		sort(arr, arr+n);
		bool flag=false;
		for(i=0;arr[i]<1.0 && i<n; i++){
			low=1.0-arr[i];
			high=2.0-arr[i];
			if(arr[i]<0.5){
				if(bsearch(i+1, n-1)){
					flag=true;
					break;
				}
			}
			else if(arr[i]>1.0){
				if(bsearch(0, i-1)){
					flag=true;
					break;
				}
			}
			else{
				if(bsearch(0, n-1)){
					flag=true;
					break;
				}
			}
		}
		if(flag)
			printf("found\n");
		else 
			printf("not found\n");
		delete arr;
	}
}
