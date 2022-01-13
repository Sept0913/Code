#include <cstdio>

#define ll long long
using namespace std;
ll n, m;
void sol(){
	scanf("%lld%lld", &n, &m);
	ll tot, p, r;
	tot = n * (n + 1) / 2;
	p = (n - m) / (m + 1);
	r = (n - m) % (m + 1);
	printf("%lld\n", tot - p * (m + 1) * (p + 1) / 2 - (p + 1) * r);
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--)
	    sol();
	return 0;
}
