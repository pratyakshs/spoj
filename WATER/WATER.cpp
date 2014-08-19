#include<bits/stdc++.h>
using namespace std;

inline int min4(int a, int b, int c, int d){
    return min(min(a,b), min(c,d));
}
int main() {
    int t;
    scanf("%i", &t);
    while(t--){
        int n, m;
        scanf("%i %i", &n, &m);
        int terrain[n+2][m+2];
        memset(&terrain[0][0], 0, sizeof(terrain));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                scanf("%i", &terrain[i][j]);
            }
        }
        bool visited[n+2][m+2];
        memset(&visited[0][0], false, sizeof(visited));
        int water=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int minH=min4(terrain[i+1][j], terrain[i][j+1],
                        terrain[i-1][j], terrain[i][j-1]);
                if(minH<terrain[i][j])
                    continue;
                else{
                    
                }
            }

    }
    return 0;

}
