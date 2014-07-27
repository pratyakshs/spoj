#include<stdio.h>
#include<stack>

using namespace std;

int main()
{
	stack<char> s;
	int count=0;
	char c;

	int cno=1;
	while(scanf("%c", &c) && c!='-')
	{
		if(c=='{')
		{
			if(!s.empty() && s.top()=='{')
				{
					s.push('{');
		//			printf("here1\n");
				}
			else if(!s.empty() && s.top()=='}')
			{
				count++;
				s.pop();
				s.push('{');
				s.push('{');
		//		printf("here1\n");
			}
			else
			{
				s.push('{');
			}
		}
		else if(c=='}')
		{
			if(!s.empty() && s.top()=='{')
				{s.pop();
					//printf("here1\n");
				}
			else
			{
				s.push('{');
				count++;
			}
		}
		else
		{
			printf("%i %i\n", cno, count+s.size()/2);
			count=0;
			cno++;
			while(!s.empty())
				s.pop();
		}
	//	scanf("%c", &c);
	}
}