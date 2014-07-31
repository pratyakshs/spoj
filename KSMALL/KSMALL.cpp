#include<bits/stdc++.h>
using namespace std;
typedef unsigned ui;
//#define XORSWAP(a, b)   ((a)^=(b),(b)^=(a),(a)^=(b))
unsigned array[5000000];

inline void XORSWAP(unsigned *x, unsigned *y) {
    unsigned temp = *x;
    *x = *y;
    *y = temp;
    return;
// if(x!=y){
  //      *x ^= *y;
    //    *y ^= *x;
      //  *x ^= *y;
   // }
}
void randomize(unsigned a,unsigned b,unsigned mod)
{
    for( int i=0 ; i<5000000 ; i++ )
    {
        a = 31014 * (a & 65535) + (a >> 16);
        b = 17508 * (b & 65535) + (b >> 16);
        array[i] = ((a << 16) + b) % mod;
    }
}
inline unsigned partition(unsigned left, unsigned right, unsigned pivotIndex) {
    unsigned pivotValue = array[pivotIndex], temp, storeIndex = left;
    array[pivotIndex] = array[right];
    array[right] = pivotValue;
    for (unsigned i = left; i < right; i++) {
        if (array[i] < pivotValue) {
            //            temp = array[storeIndex];
            //            array[storeIndex] = array[i];
            //          array[i] = temp;
            XORSWAP(&array[storeIndex], &array[i]);
            storeIndex++;
        }
    }
    //    temp = array[right];
    //  array[right] = array[storeIndex];
    //    array[storeIndex] = temp;
    XORSWAP(&array[storeIndex], &array[right]);
    return storeIndex;
}

unsigned select(unsigned left, unsigned right, unsigned n) {
    if (left == right)
        return array[left];
    srand (time(NULL));

    unsigned pivotIndex;// = left + (rand() % (right - left + 1));
    //    pivotIndex = partition(left, right, pivotIndex);
    while (true) {
        unsigned pivotIndex = left + (rand() % (right - left + 1));
        pivotIndex = partition(left, right, pivotIndex);

        if (n == pivotIndex)
            return array[n];
        else if (n < pivotIndex)
            right = pivotIndex - 1;
        else
            left = pivotIndex + 1;
    }
}
int main() {
    unsigned a, b, mod, k;
//    srand(time(NULL));
scanf("%u %u %u %u", &a, &b, &mod, &k);
//     a = 2; b = 3; mod = 100000007; k = rand()%100000;
    randomize(a, b, mod);
    printf("%u\n", select(0, 4999999, k-1));
    return 0;
}
