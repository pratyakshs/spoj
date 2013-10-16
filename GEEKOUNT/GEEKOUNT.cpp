#include<stdio.h>

using namespace std;
struct num {
	int arr[10];
	/*void print()
	{
		for(int i=0; i<10; i++)
		{
			printf("%i", arr[i]);
		}
		printf("\n");
	}*/
	bool isEven()
	{
		int i;
		for(i=0; arr[i]==0; i++);
		for(; i<10; i++)
		{
			if(!(arr[i]&1))
				return true;
		}
		return false;
	}
	void increment()
	{
		if(arr[9]!=9)
			arr[9]++;
		else
		{
			int i;
			for(i=9; i>=0; i--)
			{
				if(arr[i]!=9)
					break;
			}
			arr[i]++;
			for(int j=i+1; j<10; j++)
				arr[j]=0;
		}
	}
	num()
	{
		for(int i=0; i<10; i++)
			arr[i]=0;
	}
};

int main()
{
	int t;
	scanf("%i", &t);
	for(int i=0; i<t; i++)
	{
		unsigned int l, r;
		scanf("%u %u", &l, &r);
		unsigned int diff=r-l;
		num n; unsigned int j=9;
		unsigned int count=0,start;


		while(l>0)
		{
			n.arr[j]=l%10;
			j--;
			l/=10;
		}
		

		for(unsigned int k=0; k<=diff; k++)
		{
			//n.print();
			if(n.isEven())
				count++;
			n.increment();

		}
		printf("%u\n", count);
	}
}