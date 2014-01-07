#include<bits/stdc++.h>
int main(){
	long long d, f, b, m, p, net;
	while(scanf("%lli %lli %lli %lli", &d, &f, &b, &m)!=EOF){
		if(d==f && f==b && b==m && m==0)
			break;
		p=(f*f+f+2)/2;
		net=p*b+m-d;
		if(net>0)
			printf("The firm is trying to bankrupt Farmer Cream by %lli Bsf.\n", net);
		else
			printf("Farmer Cream will have %lli Bsf to spend.\n", -net+m);
	}
	return 0;
}
