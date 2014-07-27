#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  for(int ii=1; ii<=t; ii++){
    int n, ic=0;
    cin>>n;
    map<string, int> hashf;
    string invf[n];
    int parent[n], child[n];
    for(int i=0; i<n; i++)
      parent[i]=child[i]=n;
    string s1, s2;
    for(int i=0; i<n-1; i++){
      cin>>s1>>s2;
      if(hashf.find(s1)==hashf.end()){
	hashf[s1]=ic++;
	invf[ic-1]=s1;
      }
      if(hashf.find(s2)==hashf.end()){
	hashf[s2]=ic++;
	invf[ic-1]=s2;
      }
      int i1=hashf[s1], i2=hashf[s2];
      parent[i2]=i1;
      child[i1]=i2;
    }
    int root;
    for(int i=0; i<n; i++){
      if(parent[i]==n){
	root=i;
	break;
      }
    }
    cout<<"Scenario #"<<ii<<":"<<endl;
    while(root!=n){
      cout<<invf[root]<<endl;
      root=child[root];
    }
    cout<<endl;
  }
  return 0;
}