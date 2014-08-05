#include<bits/stdc++.h>
using namespace std;
typedef long long ull;

char line[5005];
ull *dp;
int len;

ull calc(int pos){
    if (pos > len)
        return 0LL;
    if (pos == len)
        return 1LL;
    if (dp[pos] != -1)
        return dp[pos];
    if (line[pos] == '0')
        return dp[pos] = 0LL;
    if (pos < len -1){
        if (line[pos+1] == '0') {
            if (line[pos] == '1' || line[pos] == '2')
                return dp[pos] = calc(pos+2);
            else
                return dp[pos] = 0LL;
        }
    }
    if (line[pos] == '1')
        return dp[pos] = (calc(pos+1) + calc(pos+2));
    if (line[pos] == '2'){
        if (pos < len-1) {
            if (line[pos+1] >= '0' && line[pos+1] <= '6')
                return dp[pos] = (calc(pos+1) + calc(pos+2));
            else
                return dp[pos] = calc(pos+1);
        }
        else
            return dp[pos] = 1LL;
    }
    return dp[pos] = calc(pos+1);
}
int main(){
    while (scanf("%s", line) != EOF){
        len = strlen(line);
        if (line[0] == '0' && len == 1)
            break;
        dp = new ull[len];
        for (int i = 0; i < len; i++)
            dp[i] = -1;
        printf("%lli\n", calc(0));
//        for (int i = 0; i < len; i++)
//            printf("%lli ", dp[i]);
//        printf("\n");
        delete[] dp;
    }
    return 0;
}
