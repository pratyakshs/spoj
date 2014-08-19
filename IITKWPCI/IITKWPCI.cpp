#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    scanf("%i", &t);
    while(t--) {
        scanf("%i %i", &n, &m);
        int a[n];
        for(int i=0; i<n; i++) {
            scanf("%i", &a[i]);
        }
        vector<int> adjacency[n];
        for(int i=0; i<m; i++) {
            int x, y;
            scanf("%i %i", &x, &y);
            adjacency[x-1].push_back(y-1);
            adjacency[y-1].push_back(x-1);
        }
        vector<int> visited(n, 0);
        int componentNo = 0;
        for(int i=0; i<n; i++) {
            if(visited[i] == 0) {
                componentNo++;
                stack<int> S;
                S.push(i);
                while(!S.empty()) {
                    int v = S.top();
                    visited[v] = componentNo;
                    S.pop();
                    for(int j=0; j<adjacency[v].size(); j++) {
                        if (visited[adjacency[v][j]] == 0) {
                            S.push(adjacency[v][j]);
                        }
                    }
                }
            }
        }
        vector<int> values[componentNo], keys[componentNo];
        for(int i=0; i<n; i++) {
            values[visited[i]-1].push_back(a[i]);
            keys[visited[i]-1].push_back(i);
        }
        for(int i=0; i<componentNo; i++) {
            sort(values[i].begin(), values[i].end());
            sort(keys[i].begin(), keys[i].end());
            for(int j=0; j<keys[i].size(); j++){
                a[keys[i][j]] = values[i][j];
            }
        }
        for(int i=0; i<n; i++) {
            printf("%i ", a[i]);
        }
        printf("\n");

    }
    return 0;
}
