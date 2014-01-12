#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  scanf("%i", &t);
  for(int ii=1; ii<=t; ii++){
    int n, m, v1, v2;
    scanf("%i %i", &n, &m);
    int degree[n+1];
    for(int jj=1; jj<=n; jj++) degree[jj]=0;
    for(int jj=0; jj<m; jj++){
      scanf("%i %i", &v1, &v2);
      degree[v1]++;
      degree[v2]++;
    }
    bool g4=false;
    int c[]={0, 0, 0, 0, 0};
    for(int i=1; i<=n; i++){
      if(degree[i]>4){
	g4=true;
	break;
      }
      else c[degree[i]]++;
    }
    int ans=0;
    if(g4)
      ans=3;
    else if(c[3]>0 && c[4]>0)
      ans=3;
    else if(m!=n-1)
      ans=3;
    else if(c[3]==1 && c[4]==0 && c[1]==3 && c[2]==n-4)
      ans=2;
    else if(c[4]==1 && c[3]==0 && c[1]==4 && c[2]==n-5)
      ans=1;
    else if(c[4]==0 && c[3]==0 && c[1]==2 && c[2]==n-2)
      ans=0;
    else ans=3;
    switch(ans){
      case 0: printf("Case %i: I\n", ii); break;
      case 1: printf("Case %i: X\n", ii); break;
      case 2: printf("Case %i: Y\n", ii); break;
      case 3: printf("Case %i: NotValid\n", ii); break;
      default: printf("error\n");
    }
  }
  return 0;
} 