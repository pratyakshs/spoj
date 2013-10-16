#include<stdio.h>

int main()
{
	int t;
	int max=0;
	scanf("%i", &t);
	bool arr[20001];
	for(int j=0; j<20001; j++)
		arr[j]=false;

	int count=0;

	for(int j=0; j<t; j++)
	{
		int pos;
		scanf("%i", &pos);
		if(pos>max)
			max=pos;
		arr[pos-1]=true;
		int ans=0, i=0;

		for(; arr[i]==true; i++)
		{
			
		}
		if(i>0)
			ans++;
		for(; i<=max; i++)
			if(arr[i]==true && arr[i-1]==false)
				ans++;
			printf("%i\n", ans);
		}
		printf("Justice\n");
		return 0;
	}