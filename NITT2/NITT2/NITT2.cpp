#include<stdio.h>
#include<iostream>
using namespace std;
char n[50000];
int len;

int length()
{
	int i=0;
	for(; n[i]!='\0'; i++);
		return i;
}
int main()
{	
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		scanf("%s", n);
		len=length();
		if(len<3)
		{
			if(len==1)
			{
				if(n[0]==48)
				{
					printf("Yes Yes\n");
					continue;
				}
			}
			else
			{
				printf("No No\n");
				continue;
			}
		}
		bool d252=true, d525=true;
		int l2d=10*(n[len-2]-48)+n[len-1]-48;
		
		if(l2d%25!=0)
		{
			d525=false;
		}
		if(l2d%4!=0)
		{
			d252=false;
		}
		
		if(d252 || d525)
		{
			int sum=0;
			for(int j=0; j<len; j++)
			{
				sum+=n[j]-48;
			}
			if(sum%3!=0)
			{
				d252=false;
				d525=false;
			}
			if(d252)
			{
				if(sum%9!=0)
					d252=false;
			}
		}
		if(d252 || d525)
		{
			int arr[6]={1, 3, 2, 6, 4, 5};
			unsigned long long d7=0;
			for(int j=0; j<len; j++)
			{
				int j_=j%6;
				d7+=(n[len-1-j]-48)*arr[j_];
			}
			if(d7%7!=0)
			{
				d252=false;
				d525=false;
			}
		}
		if(d252)
			printf("Yes ");
		else
			printf("No ");
		if(d525)
			printf("Yes\n");
		else
			printf("No\n");

	}
	return 0;
}