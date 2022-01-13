#include <cstdio>

#define N 300010
#define ll long long
#define ull unsigned long long
using namespace std;
ll a[N];
int n;
ull s, m[N];
ll sum = 0, cnt = 0; 
int main(){
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
	    scanf("%lld%llu", &a[i], &m[i]);
	    sum += a[i];
	}
	for(int i = 0 ; i < 62 ; i++){
		cnt = 0;
		for(int j = 0 ; j < n ; j++)
			if(m[j] >= (1ull << i) && m[j] < (1ull << i + 1))
			    cnt += a[j];
		if(cnt != 0 && (cnt > 0) == (sum > 0)){
			s |= 1ull << i;
			for(int j = 0 ; j < n ; j++)
			    if(m[j] >> i & 1) a[j] = -a[j];
		}
	}
	printf("%llu\n", s);
	return 0;
}
