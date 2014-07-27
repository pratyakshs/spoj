#include<iostream>
using namespace std;

int main()
{
	int count=0;
	for(int i=1000;i<=9999; i++)
	{
		if(i%495==0)
			{
				cout<<i;
				break;
			}
		/*
		int j=i;
		int d1=j%10;
		j/=10;
		int d2=j%10;
		j/=10;
		int d3=j%10;
		j/=10;
		int d4=j%10;
		j/=10;
		int d5=j%10;
		if(d1!=d2 && d2!=d3 && d3!=d4 && d4!=d5 && d5!=d1 && d1!=d3 && d1!=d4 && d2!=d4 && d2!=d5 && d3!=d5)
		{
			count++;
			cout<<i<<endl;
		}*/
	}
	cout<<endl<<count<<endl;

}