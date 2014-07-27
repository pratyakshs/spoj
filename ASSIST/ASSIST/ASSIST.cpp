#include<stdio.h>
#include<vector>
#include<list>
using namespace std;
list<int> nums;
int main(){
	vector<int> primes;
	primes.reserve(3094);
	for(int i=2; i<35000; i++)
		nums.push_back(i);
	while(nums.empty()==false){
		int x=*(nums.begin());
		primes.push_back(x);
		for(list<int>::iterator it=nums.begin(); it!=nums.end(); ){
			list<int>::iterator itx=it;
			for(int i=0; i<x && it!=nums.end(); i++) it++;			
			nums.erase(itx);
		}
	}
	int n;
	while(scanf("%i", &n)!=EOF){
		if(n==0)
			break;			
		printf("%i\n", primes[n-1]);
	}
	return 0;
}	

