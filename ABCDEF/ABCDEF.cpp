#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<iterator>
#include<streambuf>
#include<sstream>
#include<list>
#include<stack>
#include<ostream>
#include<bitset>
using namespace std;
const int MAX=1000001;
int arr1[MAX],arr2[MAX],v[101],cnt1[MAX],cnt2[MAX];
int main(){
	int i,n,j,k;
	scanf(" %d",&n);
	for(i=0;i<n;i++) scanf(" %d",&v[i]);
	sort(v,v+n);
	int i1,i2;
	i1=i2=0;
	for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++) arr1[i1++]=v[i]*v[j] + v[k];
	for(i=0;i<n;i++){if(v[i]==0) continue; for(j=0;j<n;j++) for(k=0;k<n;k++) arr2[i2++]=v[i]*(v[j] + v[k]);}
	sort(arr1,arr1+i1);
	sort(arr2,arr2+i2);
	//for(i=0;i<i1;i++) printf("%d,",arr1[i]); printf("\n");
	//for(i=0;i<i2;i++) printf("%d,",arr2[i]); printf("\n");
	int j1=0,j2=0;
	arr1[j1]=arr1[0];
	arr2[j2]=arr2[0];
	cnt1[j1]=cnt2[j2]=1;
	for(i=1;i<i1;i++)
	{
		if(arr1[i]==arr1[j1]) cnt1[j1]++;
		else arr1[++j1]=arr1[i],cnt1[j1]++;
	}

	for(i=1;i<i2;i++)
	{
		if(arr2[i]==arr2[j2]) cnt2[j2]++;
		else arr2[++j2]=arr2[i],cnt2[j2]++;
	}

	//for(i=0;i<=j1;i++) printf("%d,",arr1[i]); printf("\n");
	//for(i=0;i<=j2;i++) printf("%d,",arr2[i]); printf("\n");
	int s1,s2;
	s1=s2=0;
	long long ans=0;
	for( ;s1<=j1 && s2<=j2;){
		if(arr1[s1]==arr2[s2]) ans+=1LL*cnt1[s1]*cnt2[s2],s1++,s2++;
		else {
			if(arr1[s1] > arr2[s2]) s2++;
			else s1++;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
/*#include<stdio.h>

int main()
{
	int n, count=0;
	scanf("%i", &n);
	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%i", &arr[i]);
	
	for(int e=0; e<n; e++)
	{
		for(int f=0; f<n; f++)
		{
			int g=arr[e]+arr[f];

		}
	}
	printf("%i\n", count);
	return 0;
}*/















/*for(int a=0; a<n; a++){
		for(int b=0; b<n; b++){
			for(int c=0; c<n; c++){
				for(int d=0; d<n; d++){
					for(int e=0; e<n; e++){
						for(int f=0; f<n; f++){
							if((arr[f]+arr[d])*arr[e]==(arr[a]*arr[b])+arr[c])
								count++;
						}
					}
				}
			}
		}
	}*/