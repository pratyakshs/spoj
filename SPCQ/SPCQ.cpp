#include<bits/stdc++.h>
inline int sumdig(unsigned long long n){
  int sum=0;
  while(n){
    sum+=n%10;
    n/=10;
  }
  return sum;
}
int main(){
  int t;
  unsigned long long n;
  scanf("%i", &t);
  while(t--){
    scanf("%llu", &n);
    while(n%sumdig(n)!=0){
      n++;
    }
    printf("%llu\n", n);
  }
  return 0;
}
    
    