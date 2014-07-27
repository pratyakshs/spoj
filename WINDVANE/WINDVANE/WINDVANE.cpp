#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
vector<char*> matrix;

char change(int res, char c)
{
	if(res==0)
	{
		return c;
	}
	else if(res==1)
	{
		switch(c)
		{
			case 'N': return 'E'; 
			case 'E': return 'S';
			case 'S': return 'W';
			case 'W': return 'N';  
		}
	}
	else if(res==2)
	{
		switch(c)
		{
			case 'N': return 'S'; 
			case 'E': return 'W';
			case 'S': return 'N';
			case 'W': return 'E';  
		}
	}
	else if(res==3)
	{
		switch(c)
		{
			case 'N': return 'W'; 
			case 'E': return 'N';
			case 'S': return 'E';
			case 'W': return 'S';  
		}
	}

}
struct s{
int x1, y1, x2, y2, d;
s(int a, int b, int c, int e, int f)
{
	x1=a;
	y1=b;
	x2=c;
	y2=e;
	d=f;
}
};
int main()
{
	int m, n;
	scanf("%i %i", &m, &n);
//	char matrix[m][n];
	for(int i=0; i<m; i++)
	{
		char *line=new char[n];
		scanf("%s", line);
		matrix.push_back(line);
	}

	vector<s> commands;
	int c;
	scanf("%i", &c);
	//printf("%i\n", c);
	for(int i=0; i<c; i++)
	{
		char comm;
		cin>>comm;
		//printf("%c\n", comm);
		if(comm=='C')
		{
			//printf("here2\n");
			int x1, y1, x2, y2, d;

			scanf("%i %i %i %i %i", &x1, &y1, &x2, &y2, &d);
			s s1(x1, y1, x2, y2, d);
			commands.push_back(s1);
		
		}
		else
		{
			//printf("here3\n");
			int x, y;
			scanf("%i %i", &x, &y);
			int res=0;
			for(int j=0; j<commands.size(); j++)
			{

				if(x<=commands[j].x2 && x>=commands[j].x1 && y<=commands[j].y2 && y>=commands[j].y1)
				{
					if(commands[j].d)
						res--;
					else
						res++;
				}
			

			}
			res+=4*commands.size();
				res%=4;
				//cout<<"res="<<res<<endl;
				cout<<change(res, matrix[x-1][y-1])<<endl;;

		}
	}
	return 0;
}