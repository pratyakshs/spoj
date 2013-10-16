#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	while(1)
	{
		int c;
		cin>>c;
		if(c==0)
			break;
		string s;
		cin>>s;
		int r=s.length()/c;
		///cout<<r;
		for(int i=0; i<c; i++)
		{
			for(int j=0; j<r; j++)
			{
				if(j%2)
					printf("%c", s[(j+1)*c-i-1]);
				else
					printf("%c", s[i+j*c]);
			}
		}
		printf("\n");
	}
}
//0 2c-1 2c   4c-1 4c 6c-1 6c ...
//1 2c-2 2c+1 4c-2 4c+1 ...  
