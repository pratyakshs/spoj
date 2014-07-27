#include<bits/stdc++.h>
using namespace std;
int main(){
	int x, a, b, tmp;
	scanf("%i %i %i", &x, &a, &b);
	int parent[x+1];
	vector<int> *adj=new vector<int>[x+1];
	for(int i=1; i<a; i++){
		scanf("%i", &parent[i]);
		adj[i].push_back(parent[i]);
		adj[parent[i]].push_back(i);
	}
	parent[a]=a;
	for(int i=a+1; i<=x; i++){
		scanf("%i", &parent[i]);
		adj[i].push_back(parent[i]);
		adj[parent[i]].push_back(i);
	}
	queue<int> bfsQueue;
	bfsQueue.push(b);
	bool visited[x+1];
	for(int i=0; i<=x; i++) visited[i]=false;
	while(!bfsQueue.empty()){
		tmp=bfsQueue.front();
		visited[tmp]=true;
		bfsQueue.pop();
		for(int i=0; i<adj[tmp].size(); i++){
			if(!visited[adj[tmp][i]]){
				bfsQueue.push(adj[tmp][i]);
				parent[adj[tmp][i]]=tmp;
			}
		}
	}
	for(int i=1; i<b; i++)
		printf("%i ", parent[i]);
	for(int i=b+1; i<=x; i++)
		printf("%i ", parent[i]);	
	return 0;
}
