#include<stdio.h>
#define bignum unsigned long long
int mod;

inline bignum f(int n, int arr[]){


	if(n==1)
		return 1;
	if(n==2)
		return 1;
	if(n<10000000 && arr[n])
		return arr[n];
	int k=n>>1;
	bignum fkp1=f(k+1, arr);
	bignum fk=f(k, arr);
	if(n<10000000){
		if(n&1)
			return arr[n]=((fkp1*fkp1)+(fk*fk))%mod;
		return arr[n]=(fk*(((fkp1<<1)-fk)+mod))% mod;

	}	
	if(n&1)
		return ((fkp1*fkp1)+(fk*fk))%mod;
	return (fk*(((fkp1<<1)-fk)+mod))% mod;

}
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		bignum n;
		scanf("%llu %i", &n, &mod);
		int *arr=new int[10000000];
		printf("%llu\n", ((2*f(n+2, arr)+(mod-1)*(n+2))%mod));
		delete[] arr;

	}
	return 0;
}


