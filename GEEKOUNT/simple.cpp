#include<stdio.h>
#include<math.h>
#include<vector>
#include<cstdlib>
using namespace std;

int numdig(unsigned int n)
{
	int i=0;
	while(n>0)
	{
		n/=10;
		i++;
	}
	return i;
}

int count;
std::vector<int> v;
int nestedfor(int k, int ans, unsigned int l, unsigned int r)
{
	if(k==0)
		return ans;
	else
	{
		for(int i=1; i<=9; i+=2)
		{
			int m=nestedfor(k-1, ans*10+i, l, r);
			if(m==134524928 || m==0)
			{
				continue;}
				if(m<=r && l<=m)
				{
					count++;
				//	v.push_back(m);
				//	printf("%i\n", m);
				}
			}
		}
	}

	int main()
	{
		int t;
		scanf("%i", &t);
		for(int i=0; i<t; i++)
		{
			v.clear();
			unsigned int l, r;
			scanf("%u %u", &l, &r);
		//nestedfor(l, 0, l, r);
			int n1=numdig(l), n2=numdig(r);
			count=0;
			for(int i=n1; i<=n2; i++)
				nestedfor(i, 0, l, r);
			printf("%i\n", r-l+1-count);
			
		}
	}