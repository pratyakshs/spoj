#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, c=-1;
    scanf("%i %i", &n, &m);
    vector<int> adjlist[n];
    
    for(int i=0; i<m; i++) {
        int x,y;
        scanf("%i %i", &x, &y);
        adjlist[x-1].push_back(y-1);
        adjlist[y-1].push_back(x-1);
    }
    stack<int> dfstack;
    bool visited[n];
    memset(visited, false, sizeof(visited[0])*n);
    for(int i=0; i<n; i++) {
        if (!visited[i]){
            c++;
            dfstack.push(i);
            while(!dfstack.empty()){
                int v=dfstack.top();
                dfstack.pop();
                visited[v] = true;
                for(int j=0; j<adjlist[v].size(); j++){
                    if (!visited[adjlist[v][j]])
                        dfstack.push(adjlist[v][j]);
//                    visited[adjlist[v][j]] = true;
                }
            }
        }
    }
    printf("%i\n", c);
    return 0;

}
