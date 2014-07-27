#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main(){
	int t;
	scanf("%i", &t);
	for(int k=1; k<=t; k++){
		map<int, vector<int> > m;
		int x, n;
		scanf("%i %i", &x, &n);
		int arr[n];
		for(int i=0; i<n; i++){
			scanf("%i", &arr[i]);
			m[arr[i]].push_back(i);
		}
		unsigned long long count=0;
		int prev=-1;
		for(int i=0; i<n; i++){
			
				if(x-arr[i]==arr[i]){
					int s=((m.find(arr[i]))->second).size();
					count+=(s-1);
				}
				else{
					map<int, vector<int> >::iterator it=m.find(x-arr[i]);
					if(it!=m.end()){
						count+=(it->second).size();
					}
				}
		
		
			
		}
		
		printf("%i. %llu\n", k, count/2);
	}
}
// int count=0;
		// for(int i=0, j=n-1; i<j; ){
		// 	if(x<=arr[i])
		// 		break;
		// 	if(arr[i]+arr[j]==x){
		// 		count++;
		// 		i++; j--;
		// 	}
		// 	else if(arr[i]+arr[j]<k){
		// 		i++;
		// 	}
		// 	else{
		// 		j--;
		// 	}
		// }
