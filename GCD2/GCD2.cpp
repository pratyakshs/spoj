#include<bits/stdc++.h>
using namespace std;
int mod(char b[], int a){
    long long int ans=0, tmp;
    for(int i=0; b[i]!='\0'; i++){
        tmp=(ans*10+(b[i]-'0'));
        if(tmp==0)
            continue;
        else
            ans=tmp%a;
//        printf("ans = %lli\n", ans);
    }
    return ans;
}
int main(){
    int t, a, c;
    char b[255];
    scanf("%i", &t);
    while(t--){
        scanf("%i %s", &a, b);
        //printf("%i\n", mod(b,a));
        if(a==0)
            printf("%s\n", b);
        else
            printf("%i\n", __gcd(a, mod(b, a)));
    }
    return 0;
}
