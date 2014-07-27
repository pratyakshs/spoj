//segmented sieve passes
#include<bits/stdc++.h>
using namespace std;

const int L1D_CACHE_SIZE = 4096*8;
vector<int> primes, next;
int* primecount=new int[10000001];
void segmented_sieve(int64_t limit, int segment_size = L1D_CACHE_SIZE){
	primecount[2]=1;
	int srt = (int) std::sqrt((double) limit);
	int64_t s = 2;
	int64_t n = 3;

	char* segment=new char[segment_size];
	char *is_prime=new char[srt + 1];
	for(int i=0; i<srt+1; i++) is_prime[i]=1;
	
	for (int i = 2; i * i <= srt; i++)
		if (is_prime[i])
			for (int j = i * i; j <= srt; j += i)
				is_prime[j] = 0;

	for (int64_t low = 0; low <= limit; low += segment_size){
		fill(segment, segment+segment_size, 1);
		int64_t high = std::min(low + segment_size - 1, limit);
		for (; s * s <= high; s++)
			if (is_prime[s]){
				primes.push_back((int) s);
				next.push_back((int)(s * s - low));
			}
		for(size_t i = 1; i < primes.size(); i++){
			int j = next[i];
			for (int k = primes[i] * 2; j < segment_size; j += k)
				segment[j] = 0;
			next[i] = j - segment_size;
		}
		for (; n <= high; n+=2)
			primecount[n+1]=primecount[n]=segment[n-low]?primecount[n-1]+1:primecount[n-1];	
	}
}
int main()
{
	int64_t limit = 10000000;
	int size = L1D_CACHE_SIZE;

	segmented_sieve(limit, size);
	int t, n;
	scanf("%i", &t);
	while(t--){
		scanf("%i", &n);
		printf("%i\n", primecount[n]-primecount[((n+2)>>1)-1]);
	}
	return 0;
}
