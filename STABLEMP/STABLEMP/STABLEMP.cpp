#include<stdio.h>
#include<queue>
#include<list>
using namespace std;
int main(){
	int t, tmp;
	scanf("%i", &t);
	while(t-->0){
		int n;
		scanf("%i ", &n);
		int women[n][n], men[n][n];
		for(int i=0; i<n; i++){
			scanf("%i ", &tmp);
			for(int j=0; j<n; j++){
				scanf("%i ", &tmp);
				women[i][tmp-1]=j;
			}
		 }
		for(int i=0; i<n; i++){
			scanf("%i", &tmp);
			for(int j=0; j<n; j++){
				scanf("%i ", &tmp);
				men[i][j]=tmp-1;
			}
		} 
		queue<int> freemen;
		for(int i=0; i<n; i++)
			freemen.push(i);

		int menListIndex[n], womenPartner[n];
		for(int i=0; i<n; i++)
			menListIndex[i]=womenPartner[i]=-1;
		while(freemen.empty()==false){
			int curr=freemen.front(), favWomanIndex=++menListIndex[curr];
			int favWoman=men[curr][favWomanIndex];
			if(womenPartner[men[curr][favWomanIndex]]==-1){
				womenPartner[favWoman]=curr;
				freemen.pop();
			}
			else{
				if(women[favWoman][curr]<women[favWoman][womenPartner[favWoman]]){
					freemen.pop();
					freemen.push(womenPartner[favWoman]);
					womenPartner[favWoman]=curr;
				}
			}
		}
		int ans[n];
		for(int i=0; i<n; i++){
			ans[womenPartner[i]]=i;
		}
		for(int i=0; i<n; i++){
			printf("%i %i\n", i+1, ans[i]+1);
		}


	}
}

