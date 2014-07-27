#include<stdio.h>
#include<list>
//#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		int ng, nm;
		list<int> g,m;
		scanf("%i %i", &ng, &nm);
		for(int j=0; j<ng; j++)
		{
			int temp;
			scanf("%i", &temp);
			g.push_back(temp);
		}
		for(int j=0; j<nm; j++)
		{
			int temp;
			scanf("%i", &temp);
			m.push_back(temp);
		}
		g.sort();
		m.sort();
		list<int>::iterator a,b;
		for(a=g.begin(), b=m.begin(); a!=g.end() && b!=m.end(); a++, b++)
		{
			if((*a)<(*b))
			{
				b--;
			}
			else if((*a)>=(*b))
			{
				a--;
			}
		}
		if(a==g.end() && b!=m.end())
		{
			printf("MechaGodzilla\n");
		}
		else if(b==m.end() && a!= g.end())
			{
				printf("Godzilla\n");
			}
			else
				printf("uncertain\n");


	}
}