#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<list>
using namespace std;

void printVector(std::vector<int> v){
	printf("current heap: ");
	for(int i=0; i<v.size(); i++)
		printf("%i ", v[i]);
	printf("\n");
}

int main(){
	int t;
	scanf("%i",&t);

	vector<int> smaller, larger;
	int x;
	
	for(int i=0; i<t; i++){
		scanf("%i", &x);
		
		if(smaller.size()==0){
			smaller.push_back(x);
			push_heap(smaller.begin(), smaller.end());
		}
		else if(larger.size()==0 && x>smaller.front()){
			larger.push_back(-x);
			push_heap(larger.begin(), larger.end());
		}
		else if(x<=smaller.front()){
			smaller.push_back(x);
			push_heap(smaller.begin(), smaller.end());
			if(smaller.size()-larger.size()>1){
				int y=smaller.front();

				pop_heap(smaller.begin(), smaller.end());
				smaller.pop_back();

				larger.push_back(-y);
				push_heap(larger.begin(), larger.end());
			}
		}
		else if(x>(-larger.front())){
			larger.push_back(-x);
			push_heap(larger.begin(), larger.end());

			if(larger.size()-smaller.size()>1){
				int y=-(larger.front());

				pop_heap(larger.begin(), larger.end());
				larger.pop_back();

				smaller.push_back(y);
				push_heap(smaller.begin(), smaller.end());
			}
		}
		else{
			if(smaller.size()>larger.size()){
				larger.push_back(-x);
				push_heap(larger.begin(), larger.end());
			}
			else{
				smaller.push_back(x);
				push_heap(smaller.begin(), smaller.end());
			}
		}

		if(smaller.size()>=larger.size()){
			printf("%i\n", smaller.front());
		}
		else{
			printf("%i\n", -larger.front());
		}
		//printVector(smaller);
		//printVector(larger);

	}
}
