#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		char s[1001];
		scanf("%s", s);
		int size;
		int sum=0;
		for(size=0; s[size]!='\0'; size++)
		{
			sum+=s[size]-48;
		}
		sort(s, s+size);
		if(sum%3==0 && s[0]=='0')
		{
			printf("Case1\n");
			for(int j=size-1; j>=0 ; j--)
			{
				printf("%c", s[j]);
			}
			printf("\n");
			continue;
		}
		else if(sum%3==0)
		{
			printf("Case2\n");
			int j=0;
			for(;j<size; j++)
			{
				if(s[j]=='5')
					break;
			}
			if(j==size)
				continue;
			for(int k=size-1; k>=0 ; j--)
			{
				if(k==j)
					continue;
				printf("%c", s[k]);
			}
			printf("5\n");
			continue;
		}
		

		if(s[0]=='0')
		{
			int j=0;
			for(j=0; j<size; j++)
			{
				if((sum-(s[j]-48))%3==0)
					break;
			}
			printf("j=%i\n", j);

			printf("Case3\n");
			for(int k=size-1; k>=0; k--)
			{
				if(k==j)
					continue;
				printf("%c", s[k]);
			}
			printf("\n");
		}
		else
		{
			printf("Case4\n");
			int l=0;
			for(;l<size; l++)
			{
				if(s[l]=='5')
					break;
			}
			if(l==size)
				continue;

			int j=0;
		for(j=0; j<size; j++)
		{
			if((sum-(s[j]-48))%3==0 && j!=l)
				break;
		}
		if(j==size)
		printf("j=%i\n", j);
//have to correct

			for(int k=size-1; k>=0 ; k--)
			{
				if(k==l || k==j)
					continue;
				printf("%c", s[k]);
			}
			printf("5\n");
		}
		

	}
	return 0;
}