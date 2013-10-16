#include<stdio.h>
#include<set>

using namespace std;

typedef long long bigint;
bigint arr[500001];
set<bigint> s;

bigint calc(bigint m)
{
	if(arr[m]!=-1)
		{
		//	printf("Here1\n");
			return arr[m];
		}
	else
	{
		//printf("Here2\n");
		bigint a_=calc(m-1)-m;
		//printf("Here3\n");
		if(a_>0 && s.find(a_)==s.end())
		{
		//	printf("Here4\n");
			arr[m]=a_;
			s.insert(a_);
			return a_;
		}
		else
		{
		//	printf("Here5\n");
			a_=2*m+a_;
			arr[m]=a_;
			s.insert(a_);
			return a_;
		}
	}
}
int main()
{
	for(int i=0; i<=500000; i++)
		arr[i]=-1;
	arr[0]=0;
	calc(100000);
	calc(200000);
	calc(300000);
	calc(400000);

	bigint m;
	scanf("%lli", &m);
	while(m!=-1)
	{
		printf("%lli\n", calc(m));
		scanf("%lli", &m);
	}
}