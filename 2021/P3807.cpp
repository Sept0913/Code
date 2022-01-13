#include <cstdio>

#define ll long long
using namespace std;
ll f[200010];
ll n, m, mod;
void fac(){
	f[0] = 1, f[1] = 1;
	for(int i = 2 ; i <= mod ; i++)
	    f[i] = f[i] = f[i - 1] * i % mod;
}
ll qpow(ll a, ll b){
	ll base = a, ans = 1;
	while(b > 0){
		if(b & 1){
			ans *= base;
			ans %= mod;
		}
		base *= base;
		base %= mod;
		b >>= 1;
	}
	return ans % mod;
}
ll C(ll n, ll m){
	if(n < m) return 0;
	return f[n] * qpow(f[m] * f[n - m] % mod, mod - 2) % mod;
}
ll lucas(ll n, ll m){
	if(m == 0) return 1;
	return lucas(n / mod, m / mod) * C(n % mod, m % mod) % mod;
}
void Sol(){
	scanf("%lld%lld%lld", &n, &m, &mod);
	fac();
	printf("%lld\n", lucas(n + m, n));
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--)
	    Sol();
	return 0;
}
