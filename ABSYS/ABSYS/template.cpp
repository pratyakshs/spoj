#include<string>
#include<stdio.h>

using namespace std;
int length(char a[])
{
	int i=0;
	while(1==1)
	{
		if(a[i]=='\0')
			break;
		i++;
	}
	return i;
}
int convert(char a[])
{
	int ans=0;
	for(int i=0; a[i]!='\0'; i++)
	{
		ans*=10;
		ans+=a[i]-48;
	}
	return ans;
}
int main()
{
	int t;
	scanf("%i", &t);
	for(int k=0; k<t; k++)
	{
		char a[256],b[256],c[256];
		int A,B,C;
		scanf("\n%s + %s = %s", a,b,c);
		bool flag=false;
		for(int i=0; a[i]!='\0'; i++)
		{
			if(a[i]=='m')
			{
				B=convert(b), C=convert(c);
				printf("%i + %i = %i\n", C-B, B, C);
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			flag=false;
			for(int i=0; b[i]!='\0'; i++)
			{
				if(b[i]=='m')
				{
				A=convert(a), C=convert(c);
				printf("%i + %i = %i\n", A, C-A, C);
				flag=true;
				break;
				}
			}
		}
		if(!flag)
		{
			for(int i=0; c[i]!='\0'; i++)
			{
				if(c[i]=='m')
				{
				A=convert(a), B=convert(b);
				printf("%i + %i = %i\n", A, B, A+B);
				break;
				}
			}
		}
	}
	return 0;
}