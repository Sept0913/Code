#include <cstdio>

#define ll long long
using namespace std;
const ll INF = 1e18;
ll a, nw;
ll l, r;
int main(){
	scanf("%lld", &a);
	nw = ((((INF % a) * 9) % a) * 9) % a;
	l = a - nw;
	r = INF + l - 1;
	printf("%lld %lld\n", l, r);
	return 0;
}
