#include <cstdio>

#define N 1000010
#define mod 1000000007
#define ll long long
using namespace std;
int n, m;
ll fac[N], sor[N];
void pre(){
	fac[1] = 1, fac[2] = 2;
	sor[1] = 0, sor[2] = 1;
	for(int i = 3 ; i <= N - 10 ; i++){
		fac[i] = fac[i - 1] * i % mod;
		sor[i] = (i - 1) * (sor[i - 1] + sor[i - 2]) % mod;
	}
}
ll qpow(ll a, ll b){
    a %= mod;
    ll ans = 1, base = a;
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
	if(m == 0) return 1;
	return fac[n] * qpow(fac[m] * fac[n - m] % mod, mod - 2) % mod;
}
ll lucas(ll n, ll m){
	if(m == 0) return 1;
	return lucas(n / mod, m / mod) * C(n % mod, m % mod) % mod;
}
void sol(){
	scanf("%d%d", &n, &m);
	if(n == m){
		puts("1");
		return;
	}
	int c = n - m;
	if(c == 1){
		puts("0");
		return;
	}
	if(m == 0){
		printf("%lld\n", sor[n]);
		return;
	}
	printf("%lld\n", sor[c] * lucas(n, m) % mod);
}
int main(){
	pre();
	int t;
	scanf("%d", &t);
	while(t--) sol();
	return 0;
}
