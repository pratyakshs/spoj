//O(nlogn)+O(n) solution. O(nlogn) for sorting. TLE.
#include<bits/stdc++.h>
using namespace std;
double low, high;
int i; 
int main(){
	int t;
	scanf("%i", &t);
	while(t--){
		int n;
		scanf("%i", &n);
//		arr=new double[n];
		list<double> arr;
		double x;
		for(i=0; i<n; i++){
//			scanf("%lf", &arr[i]);
			scanf("%lf", &x);
			arr.push_back(x);
		}
//		sort(arr, arr+n);
		arr.sort();
		bool flag=false;
		
		for(list<double>::iterator j=arr.begin(), k=--arr.end(); j!=k;){
			double sum=*j+*k;
			if(sum<2.0 && sum>1.0){
				flag=true;
				break;
			}
			if(sum>2.0){
				k--;
			}
			else if(sum<1.0)
				j++;
		}
		if(flag)
			printf("found\n");
		else 
			printf("not found\n");
//		delete arr;
	}
}
