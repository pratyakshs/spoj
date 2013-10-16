#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%i", &t);
	bool arr[2000001];
	for(int j=0; j<2000001; j++)
		arr[j]=false;

	int count=0;

	for(int j=0; j<t; j++)
	{
		int pos;
		scanf("%i", &pos);
		pos--;
		if(!arr[pos])
		{
			if(pos==0){
				if(!arr[pos+1])
					count++;
			}
			/*else if(pos==1999){
				if(!arr[pos-1])
					count++;
			}*/
			else{
				if(arr[pos+1] && arr[pos-1])
					count--;
				else if(!arr[pos+1] && !arr[pos-1])
					count++;
			}
		}
		printf("%i\n", count);
		arr[pos]=true;
		
	}
	cout<<"Justice"<<endl;
}