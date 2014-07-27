#include<stdio.h>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
struct bag{
	int index, candies;
	bag(){
		index=candies=-1;
	}
};

struct ijk{
	unsigned long long sum;
	int i, j, k;
	ijk(){
		i=j=k=sum=0;
	}
	ijk(unsigned long long s, int a, int b, int c){
		sum=s;
		i=a;
		j=b;
		k=c;
	}
};
inline bool comp2(ijk a, ijk b){
	return a.sum<b.sum;
}
inline bool comp(bag b1, bag b2){
	return b1.candies<b2.candies;
}

int main(){
	int n;
	scanf("%i", &n);
	vector<bag> bag1(n), bag2(n), bag3(n);
	int sum1=0, sum2=0, sum3=0;
	for(int i=0; i<n; i++){
		scanf("%i %i %i", &(bag1[i].candies), &(bag2[i].candies), &(bag3[i].candies));
		bag1[i].index=bag2[i].index=bag3[i].index=i;
		sum1+=bag1[i].candies;
		sum2+=bag2[i].candies;
		sum3+=bag3[i].candies;
	}
	for(int i=0; i<n; i++){
		bag1[i].candies=sum1-bag1[i].candies;
		bag2[i].candies=sum2-bag2[i].candies;
		bag3[i].candies=sum3-bag3[i].candies;
	}
	vector<bag>::iterator it1=bag1.begin()+3, it2=bag2.begin()+3, it3=bag3.begin()+3;
	partial_sort(bag1.begin(), it1, bag1.end(), comp);
	partial_sort(bag2.begin(), it2, bag2.end(), comp);
	partial_sort(bag3.begin(), it3, bag3.end(), comp);
	
	vector<ijk> ans;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				ans.push_back(ijk(bag1[i].candies+bag2[j].candies+bag3[k].candies, bag1[i].index, bag2[j].index, bag3[k].index));
			}
			
		}
	}
	sort(ans.begin(), ans.end(), comp2);
	for(int i=0; i<9; i++){
		if(ans[i].i!=ans[i].j && ans[i].j!=ans[i].k && ans[i].i!=ans[i].k)
		{
			printf("%i\n%i\n%i\n", ans[i].i, ans[i].j, ans[i].k);

			return 0;
		}
	}

}

