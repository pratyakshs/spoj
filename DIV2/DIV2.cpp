#include<stdio.h>
#include<vector>

using namespace std;


vector<int> numDivs(1000000, 0);

int nd(int num){
	if(numDivs[num-1]!=0)
		return numDivs[num-1];
	int sum=0, step=1;
	if(num%2) step=2;
	for(int i=1; i*i<=num; i+=step)
		sum += (num%i)? 0 : ((i*i==num)? 1 : 2);
	numDivs[num-1]=sum;
	return numDivs[num-1];
}


int main(){
	vector<int> ans;
	for(int i=1; i<=1000000; i++){
		int step=1;
		if(i%2) step=2;
		bool flag=true;
		if(nd(i)>3){
			for(int j=1; j*j<=i; j+=step){
				if(i%j==0){
					if( !(nd(i)%nd(j)==0 || nd(j)%nd(i)==0) || !(nd(i)%nd(i/j)==0 || nd(i/j)%nd(i)==0))
					{
						flag=false;
						break;
					}
				}
			}
			if(flag)
				ans.push_back(i);
		}
	}
	for(int i=107; i<ans.size(); i+=108)
		printf("%i\n", ans[i]);
	// int i;

	// while(scanf("%i", &i)!=EOF){
	// 	printf("nd(i)=%i\n", nd(i));
	// 	int step=1;
	// 	if(i%2) step=2;
	// 	bool flag=true;
	// 	for(int j=1; j*j<=i; j+=step){
	// 		if(i%j){
	// 			printf("nd(j)=%i nd(i/j)=%i\n", nd(j), nd(i/j));
	// 		}
	// 	}
	// }
}