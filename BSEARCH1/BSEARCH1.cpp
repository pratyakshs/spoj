#include<stdio.h>
#include<vector>

#define sise 10000007
//hashed bsearch
int *ar;
struct pair{
	int val, pos;
	pair(int &a, int &b){
		val=a;
		pos=b;
	}
};

std::vector<pair> *table=new std::vector<pair>[sise];

int firstOccurance(std::vector<pair> &v, int &t, int p){
	//printf("t=%i pos=%i\n", t, p);
	if(p==-1)
		return -1;
	while(p>=0 && v[p].val==t){
		p--;
	}
	return v[p+1].pos;
}

int bsearch(int &t, int first, int last, std::vector<pair> &v){
	if(first>last)
		return -1;
	if(first==last)
	{
//		printf("here1\n");
		if(v[first].val==t)
			return firstOccurance(v, t, first);
		else
			return -1;
	}
	else if(last==first+1){
		if(v[first].val==t)
			return firstOccurance(v, t, first);
		else if(v[last].val==t)
			return firstOccurance(v, t, last);
		else
			return -1;
	}
	else{
		int mid=(first+last)>>1;
		if(v[mid].val==t)
			return firstOccurance(v, t, mid);
		else{
			if(v[mid].val>t)
				return bsearch(t, first, mid, v);
			return bsearch(t, mid+1, last, v);
		}
	}
}
int main(){
	int n, q, t;
	scanf("%i %i", &n, &q);
	for(int i=0; i<n; i++){
		scanf("%i", &t);
		table[(t+1000000000)%sise].push_back(pair(t, i));
	}
	for(int i=0; i<q; i++){
		scanf("%i", &t);
		int loc=(t+1000000000)%sise;
		//printf("loc=%i\n", loc);
		printf("%i\n", bsearch(t, 0, (table[loc].size())-1, table[loc]));
	}
}