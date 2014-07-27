#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string s1, s2;
    while(cin>>s1){
        if(s1[0]=='#')
            break;
        cin>>s2;
        int dptable[s1.length()+1][s2.length()+1];
        for(int i=0; i<=s1.length(); i++)
            dptable[i][0]=0;
        for(int j=0; j<=s2.length(); j++)
            dptable[0][j]=0;
        for(int i=1; i<=s1.length(); i++){
            for(int j=1; j<=s2.length(); j++){
                if(s1[i-1]==s2[j-1])
                    dptable[i][j]=dptable[i-1][j-1]+1;
                else
                    dptable[i][j]=max(dptable[i-1][j], dptable[i][j-1]);
            }
        }
        //cout<<dptable[s1.length()][s2.length()]<<endl;
        cout<<15*(s1.length()-dptable[s1.length()][s2.length()])+30*(s2.length()-dptable[s1.length()][s2.length()])<<endl;   
    }
}
