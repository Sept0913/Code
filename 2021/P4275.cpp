#include <cstdio>

#define N 1010
#define ull unsigned long long
using namespace std;
ull a[N] = {1, 1}, b[N] = {0, 1}, p = 1, n;
ull l, r;
ull Q(ull x){
	int q = 0;
	ull Ret = 0;
	while(a[q] <= x && q <= p) q++;
	for(int i = q ; i >= 0 ; i--)
	    if(a[i] <= x) x -= a[i], Ret += b[i];
	return Ret;
}
int main(){
	scanf("%*S");
	scanf("%llu", &n);
	while(a[p] < (1ull << 62))
	    a[p + 1] = a[p] + a[p - 1], b[p + 1] = b[p] + b[p - 1], p++;
	for(int i = 1 ; i <= n ; i++){
		scanf("%llu%llu", &l, &r);
		if(!l) puts("0");
		else printf("%llu\n", Q(r) - Q(l - 1));
	}
	return 0;
} 
