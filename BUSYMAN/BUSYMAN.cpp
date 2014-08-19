#include<bits/stdc++.h>
using namespace std;

struct task{
    int st, et;
};

inline bool operator<(task t1, task t2){
    if (t1.et == t2.et)
        return t1.st < t2.st;
    return t1.et < t2.et;
}

int main() {
    int t;
    scanf("%i", &t);
    while(t--){
        int n;
        scanf("%i", &n);
        task tasks[n];
        for(int i=0; i<n; i++){
            scanf("%i %i", &tasks[i].st, &tasks[i].et);
        }
        sort(tasks, tasks+n);
        int count = 1, prev = tasks[0].et;
        for(int i=1; i<n; i++){
            if(prev <= tasks[i].st){
                count++;
                prev = tasks[i].et;
            }
        }
        printf("%i\n", count);
    }
    return 0;

}
