#include<list>
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	//list<int> L;
	map<int, int> m;
	
	//list<int>::iterator it
	scanf("%i", &n);
	for(int i=0; i<n; ++i)
	{
		bool homo=false, hetr=false;
		char c[7];
		int x;
		scanf("%s", c);
		scanf("%i", &x);

		if(c[0]=='i')
		{	
			m[x]++;
		}
		else if (c[0]=='d')
		{	
			if(m[x])
				m[x]--;
		}
		map<int, int>::iterator it=m.begin();
		int hetcount=0, homocount=0;
		for(; it!=m.end(); it++)
		{
			if(it->second>=2)
			{
				homocount++;
			}	
		}

		if(homocount>=2)
		{
			hetr=homo=true;
		}
		else if(homocount==1) homo=true;


		if(!hetr)
		{	for(it=m.begin(); it!=m.end() && hetcount<=2; it++)
			{
				if(it->second==1)
					hetcount++;
			}
			if(hetcount>=2)
				hetr=true;
		}
		if(hetcount==1 && homo) hetr=true;


		if(homo && hetr)
			printf("both\n");
		else if(homo)
			printf("homo\n");
		else if(hetr)
			printf("hetero\n");
		else
			printf("neither\n");																																																																																											
	}
	return 0;
}
