#include <cstdio>
#include <cmath>

#define ll long long
using namespace std;
ll n, b;
bool check(ll k){
	ll cnt = 0;
	ll m = n;
	while(m > 0){
		if(m <= k){
			cnt += m;
			break;
		}
		cnt += k;
		m -= k;
		m -= m / 10;
	}
	return cnt >= b;
}
int main(){
	scanf("%lld", &n);
	b = (n + 1) / 2;
	ll l = 1, r = n;
	while(l < r){
		ll mid = l + r >> 1;
		if(check(mid))
		    r = mid;
		else
		    l = mid + 1;
	}
	printf("%lld\n", l);
	return 0;
}
