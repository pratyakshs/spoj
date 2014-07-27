#include<bits/stdc++.h>
int main(){
  int t, v, n;
  scanf("%i", &t);
  while(t--){
    scanf("%i", &n);
    bool flag=true;
    for(int i=0; i<n; i++){
      scanf("%i", &v);
      if(v>i)
	flag=false;
    }
    if(flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}