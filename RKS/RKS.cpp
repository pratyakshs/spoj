#include<bits/stdc++.h>
using namespace std;
struct num{
	int val, count, index;
	num(int v, int c, int i){ val=v; count=c; index=i;}
};
bool operator<(num a, num b){
         if(a.count==b.count)
                 return a.index<b.index;
         else return a.count>b.count;
}
int main(){
	int n, c, x;
	scanf("%i %i", &n, &c);
	map<int, pair<int, int> > s;
	for(int i=0; i<n; i++){
		scanf("%i", &x);
		map<int, pair<int, int> >::iterator it=s.find(x);
		if(it!=s.end()) it->second.second++;
		else s[x]=make_pair(i, 1);
	}
	vector<num> v;
	for(map<int, pair<int, int> >::iterator it=s.begin(); it!=s.end(); it++) v.push_back(num(it->first, it->second.second, it->second.first));
	sort(v.begin(), v.end());
	for(vector<num>::iterator it=v.begin(); it!=v.end(); it++){
		for(int i=0; i<it->count; i++)
			printf("%i ", it->val);
	}
	printf("\n");
	return 0;
}



			


