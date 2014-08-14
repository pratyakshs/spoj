#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    vector<vector<int> > adjacency(n+1, vector<int>());
    vector<pair<int, int> > input;
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%i %i", &a, &b);
        input.push_back(make_pair(a,b));
        adjacency[a].push_back(b);
    }

    vector<vector<bool> > marked(n+1, vector<bool>(n+1, true));
    bool explored[n+1];
    fill_n(explored, n+1, false);
    for(int i=1; i<=n; i++) {
        vector<bool> done(n+1, false);
        for(vector<int>::iterator it = adjacency[i].begin(); it != adjacency[i].end(); it++) {
            stack<int> S;
            S.push(*it);
            while(!S.empty()){
                int v = S.top();
                S.pop();
                for(vector<int>::iterator j = adjacency[v].begin(); j != adjacency[v].end(); j++) {
                    if (!done[*j]) {
                        S.push(*j);
                        done[*j] = true;
                    }
                }
            }
            for(int j=1; j<=n; j++) {
                if (done[j])
                marked[i][j] = false;
            }
        }
    }
    int ansSize = 0;
    for(int i = 0; i < m; i++) {
        if (marked[input[i].first][input[i].second])
            ansSize ++;
    }
    printf("%i\n", ansSize);
    for(int i = 0; i < m; i++) {
        if (marked[input[i].first][input[i].second])
            printf("%i %i\n", input[i].first, input[i].second);
    }
    return 0;
}
