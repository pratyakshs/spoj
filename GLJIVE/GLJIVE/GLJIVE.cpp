#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10];

int main()
{
	int total=0, i;
	for(i=0; i<10; i++)
	{
		scanf("%i", &a[i]);
		total+=a[i];
		if(total>100)
			break;
	}
	if(abs(total-100)>abs(total-100-a[i]))
		total=total-a[i];
	printf("%i\n", total);
	return 0;
}