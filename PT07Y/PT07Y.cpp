#include<stdio.h>
#include<list>
#include<vector>
#include<cstdlib>
using namespace std;
vector<list<int> > adjacency;
vector<int> color;
vector<int> parent;
void DFS(int v){
	color[v]=1;
	for(list<int>::iterator it=adjacency[v].begin(); it!=adjacency[v].end(); it++){
		if(color[*it]==0){
		//	color[*it]=1;
			parent[*it]=v;
			DFS(*it);
		}
		else if(*it!=parent[v]){
			printf("NO\n");
			exit(0);
		}
	}
	color[v]=2;
}
int main(){
	int n, m;
	scanf("%i %i", &n, &m);
	adjacency.resize(n);
	while(m--){
		int a, b;
		scanf("%i %i", &a, &b);
		a--; b--;
		adjacency[a].push_back(b);
		adjacency[b].push_back(a);
	}
	color.resize(n);parent.resize(n);
	for(int i=0; i<n; i++)
		color[i]=parent[i]=0;
	DFS(0);
	for(int i=0; i<n; i++){
		if(color[i]==0){
			printf("NO\n");
			exit(0);
		}
	}
	printf("YES\n");
}
