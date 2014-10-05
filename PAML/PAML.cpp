#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x;
    scanf("%i", &t);
    for(int tt = 1; tt <= t; tt++){
        scanf("%i", &n);
        multiset<int> input;
        while(n--){
            scanf("%i", &x);
            input.insert(x);
        }
        int n_partitions = 0, max_height = 0, curr_height = 0;
        while(!input.empty()) {
            curr_height = 1;
            int top = *(input.begin());
            input.erase(input.begin());
            
            multiset<int>::iterator it = input.lower_bound(max(curr_height, top));
            while(it != input.end()) {
                curr_height++;
                top = *it;
                input.erase(it);
                it = input.lower_bound(max(curr_height, top));
            }
            max_height = max(curr_height, max_height);
            n_partitions++;
        }
        printf("Case #%i: %i %i\n", tt, n_partitions, max_height);
    }
    return 0;
}
