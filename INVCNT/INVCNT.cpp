#include<stdio.h>
typedef long long bigint;
bigint count=0;
bigint *merge(bigint left[], bigint right[], bigint a, bigint b)
{
	bigint i=0, j=0;
	bigint *ans=new bigint[a+b];
	for(; i<a && j<b; )
	{
		if(left[i]<=right[j])
			ans[i+j]=left[i++];

		else
		{
			ans[i+j]=right[j++];
			count+=a-i;
		}
	}
	if(i==a)
	{
		for(; j<b; j++)
			ans[j+i]=right[j];
	}
	else if(j==b)
	{
		for(; i<a; i++)
			ans[j+i]=left[i];
	}
	return ans;
}

bigint *sort(bigint arr[], bigint n)
{
	if(n==1)
	{
		bigint *ans=new bigint[1];
		ans[0]=arr[0];
		return ans;
	}
	bigint *left=sort(arr, n/2);
	bigint *right=sort(&arr[n/2], n-(n/2));
	
	//printf("\nleft: ");
	//for(bigint i=0; i<n/2; i++)
//		printf("%lli", left[i]);


	//printf(" right: ");
	//for(bigint i=0; i<n-n/2; i++)
	//	printf("%lli", right[i]);

	return merge(left, right, n/2, n-(n/2));
}
int main()
{
	bigint t;
	scanf("%lli", &t);

	for(bigint i=0; i<t; i++)
	{
		bigint n;
		count=0;
		scanf("%lli", &n);
		bigint arr[n];
		for(bigint j=0; j<n; j++)
		{
			scanf("%lli", &arr[j]);
		}
		sort(arr, n);
		//printf("\nans: ");
		//for(bigint j=0; j<n; j++)
		//	printf("%lli ", x[j]);
		printf("%lli\n", count);

	}
	return 0;
}