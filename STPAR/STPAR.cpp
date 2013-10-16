#include<stack>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	while(true)
	{
		scanf("%i", &n);
		if(n==0)
			break;

		int j=1;
		bool flag=true;
		stack<int> res;
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%i", &x);
			while(!res.empty() && res.top()==j)
			{
				j++;
				res.pop();
			}
			if(x==j)
			{
				j++;
			//	printf("out\n");
			}
			else
			{
				res.push(x);
			//	printf("keep\n");
			}
		}
		//printf("j==%i\n", j);
		while(!res.empty())
		{
			if(res.top()==j)
			{
				j++;
				res.pop();
			}	
			else
			{
				flag=false;
				break;
				
			}
			
		}
			
		if(flag)
			printf("yes\n");
		else
			printf("no\n");

	}
}