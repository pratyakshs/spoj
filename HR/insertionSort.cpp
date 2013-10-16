#include <iostream>
#include <vector>
using namespace std;
/* Head ends here */
int cot;
void insertionSort(vector <int> &ar, int _ar_size) {
 int v=ar[_ar_size-1];
 //cout<<"v="<<v<<endl;
 int i;
 for(i=_ar_size-1; i>=0; i--)
 {
  if(ar[i-1]>v)
  {
    ar[i]=ar[i-1]; 
    //cot++;
    
  }
  else
  {
    if(i==0 && v<ar[0])
     ar[0]=v;

   ar[i]=v;
  // cout<<"here";
   cot+=_ar_size-1-i;

   return;

 }
}
if(i==-1 && v<ar[0])
{
  
  cot+=_ar_size-1;
}



}
void mainsort(vector<int> ar, int _ar_size)
{
  for(int i=2; i<=_ar_size; i++)
  {
    insertionSort(ar, i);
  }
}



/* Tail starts here */
int main(void) {
  cot=0;
 vector <int>  _ar;
 int _ar_size;
 cin >> _ar_size;
 for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
 }

 mainsort(_ar, _ar_size);
 cout<<cot;

 return 0;
}