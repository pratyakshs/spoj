#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef long long bigint;
void initialize(bigint node, bigint b, bigint e, std::vector<bigint> &M, bigint A[], bigint N)
{
  if (b == e)
    M[node] = b;
  else
  {
  //compute the values in the left and right subtrees
    initialize(2 * node, b, (b + e)>>1, M, A, N);
    initialize(2 * node + 1, ((b + e) >>1) + 1, e, M, A, N);
  //search for the minimum value in the first and 
  //second half of the biginterval
    if (A[M[2 * node]] <= A[M[2 * node + 1]])
      M[node] = M[node<<1];
    else
      M[node] = M[(node<<1) + 1]; 
  }
} 

bigint query(bigint node, bigint b, bigint e, std::vector<bigint> &M, bigint A[], bigint i, bigint j)
{
  bigint p1, p2; 
  //if the current biginterval doesn't bigintersect 
  //the query biginterval return -1
  if (i > e || j < b)
    return -1;

  //if the current biginterval is included in 
  //the query biginterval return M[node]
  if (b >= i && e <= j)
    return M[node];

  //compute the minimum position in the 
  //left and right part of the biginterval
  p1 = query(2 * node, b, (b + e) >>1, M, A, i, j);
  p2 = query(2 * node + 1, ((b + e)>>1)+ 1, e, M, A, i, j);

  //return the position where the overall 
  //minimum is
  if (p1 == -1)
    return M[node] = p2;
  if (p2 == -1)
    return M[node] = p1;
  if (A[p1] <= A[p2])
    return M[node] = p1;
  return M[node] = p2;


}
bigint lg2(bigint v){


  v--;
v |= v >> 1;  //take care of 2-bit word
v |= v >> 2;  //take care of 4-bit word
v |= v >> 4;  //take care of 8-bit word
v |= v >> 8;  //take care of 16-bit word
v |= v >> 16; //take care of 32-bit word
v++;
return v;
}
int main(){
  bigint t;
  scanf("%lli", &t);
  for(bigint i=0; i<t; i++){
    bigint n, q;
    scanf("%lli %lli", &n, &q);
    bigint arr[n];
    bigint size= 1+(lg2(n)<<1);
    bigint s = size>>1;
    vector<bigint> M(1+(lg2(n)<<1), -1);
    for(bigint j = 0; j<size; j++)
      M[j]=-1;

    for(bigint j=0; j<n; j++)
      scanf("%lli", &arr[j]);

    initialize(1, 0, n-1, M, arr, n);
    printf("Scenario #%lli:\n\n", i+1);
    for(bigint j=0; j<q; j++){
      bigint x, y;
      scanf("%lli %lli", &x, &y);
      printf("%lli\n\n", arr[query(1, 0, n-1, M, arr, x-1, y-1)]);
    }

  }
}