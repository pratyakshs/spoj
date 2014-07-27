#include<stdio.h>
#include<set>

using namespace std;

int main()
{
	int n;
	scanf("%i", &n);
	set<int> s;
	for(int i=0; i<n; i++){
		int x;
		scanf("%i", &x);
		pair<set<int>::iterator, bool> p=s.insert(x);
		if(!(p.second))
			s.erase(p.first);
	}
printf("%i\n", *(s.begin()));
}