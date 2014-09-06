#include<bits/stdc++.h>
using namespace std;
#define mod 2147483647
typedef long long ll;
int main() {
    ll n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    string *input = new string[n];
    for(int i=0; i<n; i++)
        cin >> input[i];
    char grid[n+2][n+2];
    for(int i=0; i<n+2; i++)
        grid[0][i] = grid[i][0]
            = grid[n+1][i] = grid[i][n+1] = '#';
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i+1][j+1] = input[i][j];
        }
    }
    delete[] input;
//    ll numpaths[n+2][n+2];
    ll **numpaths = new ll*[n+2];
    for(int i=0; i<n+2; i++) 
        numpaths[i] = new ll[n+2];

    for(int i=0; i<n+2; i++)
        for(int j=0; j<n+2; j++)
            numpaths[i][j] = 0;
    numpaths[1][1] = 1;

    for(int i=1; i<n+2; i++) {
        for(int j=1; j<n+2; j++) {
            if (grid[i][j] == '#')
                numpaths[i][j] = 0;
            else 
                numpaths[i][j] = (numpaths[i-1][j]
                        + numpaths[i][j-1]) % mod;
            numpaths[1][1] = 1;
        }
    }
    if (numpaths[n][n] > 0) {
        cout << numpaths[n][n] << endl;
    }
    
    else {
        for(int i = 0; i < n+2; ++i) {
                delete [] numpaths[i];
        }
        delete [] numpaths;

        bool **visited = new bool*[n+2];
        for(int i=0; i<n+2; i++)
            visited[i] = new bool[n+2];

//        memset(visited, false, sizeof(visited[0][0])*(n+2)*(n+2));
        for(int i=0; i<n+2; i++)
            for(int j=0; j<n+2; j++)
                visited[i][j] = false;

        
        stack<pair<int, int> > dfstack;
        dfstack.push(make_pair(1, 1));
        while(!dfstack.empty()) {
            pair<int, int> v = dfstack.top();
            dfstack.pop();
            int x = v.first, y = v.second;
            visited[x][y] = true;
            if (grid[x][y] == '.') {
                if (grid[x-1][y] == '.' && !visited[x-1][y])
                    dfstack.push(make_pair(x-1, y));
                if (grid[x][y-1] == '.' && !visited[x][y-1])
                    dfstack.push(make_pair(x, y-1));
                if (grid[x][y+1] == '.' && !visited[x][y+1])
                    dfstack.push(make_pair(x, y+1));
                if (grid[x+1][y] == '.' && !visited[x+1][y])
                    dfstack.push(make_pair(x+1, y));
            }
        }

        if (visited[n][n]) 
            cout << "THE GAME IS A LIE" << endl;
        else 
            cout << "INCONCEIVABLE" << endl;
    }
    
    return 0;
}



