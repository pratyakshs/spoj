#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

void calculate_s(string &p, int s[],int curr, int &i)
{
	//cout<<curr<<endl;
	if(curr<0 || curr>=p.length())
		s[i]=0;

	else if(p[i]==p[s[curr]])
	{
		s[i]=s[curr]+1;
	}
	else
		calculate_s(p, s, s[curr]-1, i);
}

void calculate_f(string &p, int s[], int curr, int &i, int f[])
{
	if(curr<0)
		f[i]=-1;
	else if(p[s[curr]]!=p[i])
		f[i]=s[curr];
	else
		calculate_f(p,s,s[curr]-1,i,f);
}

int main()
{
	int len;
	while(scanf("%i", &len)!=EOF)
		
	{
		string p;
		cin>>p;

		string t;
		cin>>t;

		
		unsigned long long count=0;

		
		
		int s[p.length()], f[p.length()];

	//---caluclate s values
		s[0]=0;

		for(int i=1; i<p.length(); i++)
		{
			calculate_s(p,s,i-1,i);
		}

	//---caluclate f values
		f[0]=-1;
		for (int i = 1; i < p.length(); ++i)
		{
			calculate_f(p,s,i-1,i,f);
		}

	//---pattern matching
		bool flag=true;
		//printf("i=%i\n", i);
		int g=0;
		for(int j=0; g<t.length(); g++) 
		{ 
			if(t[g]==p[j]) 
			{ 
				//char matched
				
				j++; 
				if(j==p.length()) 
				{ 
					printf("%i\n", g-p.length()+1);
					flag=false;
					count++;
					j=s[j-1]; 
				} 
			} 
			else if(f[j]==-1) j=0;
			else j=f[j], g--; 
		} 
		if(flag)
			printf("\n");
	}

	return 0;
}