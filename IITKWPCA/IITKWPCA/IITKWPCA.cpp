#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<stdio.h>
using namespace std;
bool isAllSpaces(string sentence){
	for(int i=0; i<sentence.length(); i++){
		if(sentence[i]!=' ')
			return false;
	}
	return true;
}

int main()
{
	int t;
	scanf("%i\n", &t);
	
	for(int i=0; i<t; i++){
		string sentence;
		getline(cin, sentence, '\n');
		if(isAllSpaces(sentence)){
			printf("0\n");
			continue;
		}
		if(sentence[0]==' ')
		{
			int i=1;
			while(sentence[i]==' ')
				i++;
			sentence=sentence.substr(i);
		}
		if(sentence[sentence.length()-1]==' ')
		{
			int i=sentence.length()-2;
			while(sentence[i]==' ')
				i--;
			sentence=sentence.substr(0, i+1);
		}
		set<string> words;
		int start=0, end=0;
		for(; end<sentence.length(); end++)
		{
			if(sentence[end]==' ')
			{
				if(sentence[end-1]==' ')
					start=end+1;
				else{
					pair<std::set<string>::iterator,bool> p=words.insert(sentence.substr(start, end-start));
					 // if(p.second)
					 // 	cout<<*(p.first)<<endl;
					start=end+1;
				}
			}
		}
		{
			pair<std::set<string>::iterator,bool> p=words.insert(sentence.substr(start, end-start));
			// if(p.second)
			// 	cout<<*(p.first)<<endl;
			//start=end;
		}
		
		printf("%u\n", words.size());
	}
}

