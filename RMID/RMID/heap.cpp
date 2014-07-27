#include<algorithm>
#include<deque>
#include<stdio.h>
using namespace std;

void printVector(std::deque<int> v){
	printf("current heap: ");
	for(int i=0; i<v.size(); i++)
		printf("%i ", v[i]);
	printf("\n");
}

int main(){
	deque<int> t;
	int x;
	while(scanf("%i", &x)!=EOF){
		if(x==-1){
			printf("removed %i\n", t.front());
			
			pop_heap(t.begin(), t.end());
			t.pop_back();
			printVector(t);
		}
		else{
			t.push_back(x);
			push_heap(t.begin(), t.end());
			printVector(t);
		}
	}
}