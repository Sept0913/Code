#include <cstdio>

#define ll long long
using namespace std;
int n, m;
ll C(ll n){
	return (n - 2) * (n - 1) * n / 6;
}
ll gcd(ll x, ll y){
	return y ? gcd(y, x % y) : x;
}
ll ans = 0;
int main(){
	scanf("%lld%lld", &n, &m);
	ans = C((n + 1) * (m + 1));
	ans -= ((n + 1) * C(m + 1) + (m + 1) * C(n + 1));
	for(ll i = 1 ; i <= n ; i++)
	    for(ll j = 1 ; j <= m ; j++)
	        ans -= 2ll * (n + 1 - i) * (m + 1 - j) * (gcd(i, j) - 1);
	printf("%lld\n", ans);
	return 0;
}
