#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */
void quickSort(vector <int>  ar, int ar_size) {
    if(ar_size==0)
      return;
    if(ar_size==1)
    {
       return;
    }
    
    else
    {
        vector <int> vl, vr;
        for(int i=1; i<ar_size; i++)
        {
            if(ar[0]>ar[i])
                vl.push_back(ar[i]);
            else
                vr.push_back(ar[i]);
        }
        quickSort(vl, vl.size());
        for(int i=0; i<vl.size(); i++)
          cout<<vl[i]<<" ";
        cout<<ar[0]<<" ";
        quickSort(vr, vr.size());
        for(int i=0; i<vr.size(); i++)
          cout<<vr[i]<<" ";
        cout<<endl;
    }


}
/* Tail starts here */
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

quickSort(_ar, _ar_size);
   
   return 0;
}