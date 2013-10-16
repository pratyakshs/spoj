#include<stdio.h>
#include<math.h>
using namespace std;
typedef long long bigint;
void initialize(int node, int b, int e, int M[], int A[], int N)
{
  if (b == e)
    M[node] = b;
  else
  {

    initialize(2 * node, b, (b + e)>>1, M, A, N);
    initialize(2 * node + 1, ((b + e) >>1) + 1, e, M, A, N);

    if (A[M[2 * node]] <= A[M[2 * node + 1]])
      M[node] = M[node<<1];
    else
      M[node] = M[(node<<1) + 1]; 
  }
} 

int query(int node, int b, int e, int M[], int A[], int i, int j)
{
  int p1, p2; 

  if (i > e || j < b)
    return -1;


  if (b >= i && e <= j)
    return M[node];

  p1 = query(2 * node, b, (b + e) >>1, M, A, i, j);
  p2 = query(2 * node + 1, ((b + e)>>1)+ 1, e, M, A, i, j);


  if (p1 == -1)
    return M[node] = p2;
  if (p2 == -1)
    return M[node] = p1;
  if (A[p1] <= A[p2])
    return M[node] = p1;
  return M[node] = p2;


}
int lg2(int v){


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
  int t;
  scanf("%i", &t);
  for(int i=0; i<t; i++){
    int n, q;
    scanf("%i %i", &n, &q);
    int *arr=new int[n];
    bigint size= 1+(lg2(n)<<1);
    bigint s = size>>1;
    int *M=new int[size];
    for(int j = 0; j<size; j++)
      M[j]=-1;

    for(int j=0; j<n; j++)
      scanf("%i", &arr[j]);

    initialize(1, 0, n-1, M, arr, n);
    printf("Scenario #%i:\n\n", i+1);
    for(int j=0; j<q; j++){
      int x, y;
      scanf("%i %i", &x, &y);
      for(int i=0; i<n; i++)
      query(1, 0, n-1, M, arr, i, i);
      printf("%i\n\n", arr[query(1, 0, n-1, M, arr, x-1, y-1)]);
    }

  }
}