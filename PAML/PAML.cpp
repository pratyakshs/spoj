#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%i", &t);
    while(t--){
        int n;
        scanf("%i", &n);
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            scanf("%i", &arr[i]);
        }
        int max=0, constraint=9999, prev=0, maxi=-1, numread=0, curheight=0, maxheight=0;
        for(int i=0; numread<n; i=(i==n-1)?0:i+1){
            if(arr[i]==-1)
                continue;
            if(arr[i]>max){
                max=arr[i];
                maxi=i;
                numread++;
                arr[i]=-1;
            }

        }
    }
    return 0;
}
