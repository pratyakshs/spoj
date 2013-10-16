#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int n1, n2, m1, m2;

void calculate_s(char p[], int s[],int curr, int &i)
{
	//cout<<curr<<endl;
	if(curr<0 || curr>=n2)
		s[i]=0;

	else if(p[i]==p[s[curr]])
	{
		s[i]=s[curr]+1;
	}
	else
		calculate_s(p, s, s[curr]-1, i);
}

void calculate_f(char p[], int s[], int curr, int &i, int f[])
{
	if(curr<0)
		f[i]=-1;
	else if(p[s[curr]]!=p[i])
		f[i]=s[curr];
	else
		calculate_f(p,s,s[curr]-1,i,f);
}

int find(int **s, int **f, char **text, char **pattern, int textLine, int patternLine)
{
	for(int g=0, j=0; g<m2; g++) 
	{ 
		if(text[textLine][g]==pattern[patternLine][j]) 
		{
			j++;
			if(j==m2) 
			{ 
				//printf("%i\n", g-p.length()+1);
				count++;
				j=s[][j-1]; 
			} 
		} 
		else if(f[j]==-1) j=0;
		else j=f[j], g--; 
	} 
}
int main()
{
	scanf("%i %i", &n1, &n2);
	char pattern[n1][n2];
	for(int i=0; i<n1; i++)
	{
		scanf("%s", pattern[i]);
	}

	scanf("%i %i", &m1, &m2);
	char text[n1][n2];
	for(int i=0; i<m1; i++)
	{
		scanf("%s", text[i]);
	}
	


	int s[n1][n2], f[n1][n2];

	//---caluclate s values
	for(int i=0; i<n1; i++){
		s[i][0]=0, f[i][0]=-1;
	}

	for(int j=0; j<n1; j++)
	{
		for(int i=1; i<n2; i++)
		{
			calculate_s(pattern[j],s[j],i-1,i);
		}
	}

	//---caluclate f values
	for(int j=0; j<n1; j++){

		for (int i = 1; i <n2; ++i)
		{
			calculate_f(pattern[j],s[j],i-1,i,f[j]);
		}
	}



	//---pattern matching
	for(int linesOfText=0; linesOfText<=m1-n1; linesOfText++)

	{

	}

	return 0;
}