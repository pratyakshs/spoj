#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

int length(char a[])
{
	int i;
	for(i=0; a[i]!='\0'; i++);
	return i;
}
int main()
{	
	char a[250001], b[250001];
	scanf("%s", a);
	scanf("%s", b);
	int la=length(a);
	int lb=length(b);
	int m=min(la+1,6000), n=min(lb+1,6000);
	int matrix[m][n];
	for(int i=0; i<m; i++)
		matrix[i][0]=0;
	for(int i=0; i<n; i++)
		matrix[0][i]=0;
	for(int i=0; i<la; i++)
        for (int j=0; j<lb; j++)
            if (a[i] == b[j])
                matrix[i][j]= matrix[i-1][j-1] + 1;
            else
                matrix[i][j]=max(matrix[i][j-1], matrix[i-1][j]);
    return matrix[m][n];
}