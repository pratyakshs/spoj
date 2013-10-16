#include<stdio.h>
//simple binary search solution
int *ar;
int firstOccurance(int &t, int pos){
	if(pos==-1)
		return -1;
	while(--pos>=0)
	{
		if(ar[pos]!=t)
			break;
	}
	return pos+1; 
}
int bsearch(int &t, int first, int last){
	if(first==last)
	{
		if(ar[first]==t)
			return firstOccurance(t, first);
		else
			return -1;
	}
	else if(last==first+1){
		if(ar[first]==t)
			return firstOccurance(t, first);
		else if(ar[last]==t)
			return firstOccurance(t, last);
		else
			return -1;
	}
	else{
		int mid=(first+last)/2;
		if(ar[mid]==t)
			return firstOccurance(t, mid);
		else{
			if(ar[mid]>t)
				return bsearch(t, first, mid);
			if(ar[mid]<t)
			  	return bsearch(t, mid+1, last);
		}
	}
}
int main(){
	int n, q, t;
	scanf("%i %i", &n, &q);
	ar=new int[n];
	for(int i=0; i<n; i++){
		scanf("%i", &ar[i]);
	}
	for(int i=0; i<q; i++){
		scanf("%i", &t);
		printf("%i\n", bsearch(t, 0, n-1));
	}
}