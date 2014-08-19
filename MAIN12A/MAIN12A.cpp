#include<bits/stdc++.h>
using namespace std;
#define MAX 1000050
int main(){
    vector<int> sequence;
    sequence.push_back(1);
    int lastnum=1, lastsize=1;
    for(int i=0; sequence.size()<MAX; i++){
        lastnum++;
        for(int j=0; j<sequence[i]; j++){
            sequence.push_back(lastnum);
        }
    }
/*    for(int i=0; i<100; i++){
        cout<<sequence[i]<<endl;
    }*/
    int t;
    scanf("%i", &t);
    for(int tt=1; tt<=t; tt++){
        int n;
        scanf("%i", &n);
        printf("Case #%i: %i\n", tt, sequence[n-1]);
    }

    return 0;
}
