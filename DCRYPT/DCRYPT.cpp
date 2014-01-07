#include<bits/stdc++.h>
using namespace std;
inline void read(string &s){
   s="";
   char ch=getchar_unlocked();
   while((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||ch=='.'){
     s.push_back(ch);
     ch=getchar_unlocked();
   }
}   
int main(){
   int t, k;
   string s;
   scanf("%i", &t);
   while(t--){
     scanf("%i\n", &k);
     read(s);
     if(k<26){
      for(int i=0; i<s.length(); i++){
	if(s[i]=='.')
	  printf(" ");
	else if(s[i]>='a' && s[i]<='z')
	  printf("%c", ((s[i]-'a'+k)%26)+'a');
	else 
	  printf("%c", ((s[i]-'A'+k)%26)+'A');
      }
     }
     else{
       for(int i=0; i<s.length(); i++){
	 if(s[i]=='.')
	   printf(" ");
	 else if(s[i]>='a' && s[i]<='z')
	   printf("%c", (s[i]-'a'+k)%26+'A');
	 else
	   printf("%c", (s[i]-'A'+k)%26+'a');
       }
     }
     printf("\n");
   }
   return 0;
}
     
     
