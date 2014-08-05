#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, len=0, p=0, curlen=0, curp=0;
    char line[30000], ch, prev=' ';
    scanf("%i\n", &t);
    while(t--){
        cin.getline(line,20005);
        for(int i=0; i<30000; i++){
//            ch=getchar_unlocked();
//            printf("read %c, len = %i, p = %i, curlen = %i, curp = %i\n", ch, len, p, curlen, curp);
            if (line[i]!=' '){
                if(prev==' ')
                    curlen=1;
                else
                    curlen++;
            }
            else{
                if(curlen==len){
                    curp++;
                    if(curp>p)
                        p=curp;
                }
                else{
                    len=curlen;
                    curp=1;
                }
            }
            if (line[i] == '\n')
                break;
            prev=line[i];
        }
    
        printf("%i\n", p);
    }

    return 0;
}


