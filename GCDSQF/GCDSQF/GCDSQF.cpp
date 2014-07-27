#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
typedef long long bigint;
typedef unsigned long long bignum;

int length(char a[])
{
	int i=0;
	for(; a[i]!='\0';i++);
	return i;
}
int main()
{	
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		char A[1001], B[1001];
		scanf("%s", A);
		scanf("%s", B);
		char C[1001], LCM[1001]; //A+B
		int lenA=length(A), lenB=length(B);
		if(lenA<lenB)
		{
			for(int j=0; j<=lenB; j++)
				C[j]=B[j], LCM[j]=B[j];
			for(int j=0; j<lenA; j++)
				C[j]+=A[j], LCM[j]=max(A[j], B[j]);
		}
		else
		{
			for(int j=0; j<=lenA; j++)
				C[j]=A[j], LCM[j]=A[j];
			for(int j=0; j<lenB; j++)
				C[j]+=B[j], LCM[j]=max(A[j], B[j]);
		}
		

		

	}
	return 0;
}