#include <cstdio>
#include <algorithm>

#define N 200010
#define ll long long
#define h(i) c[i].h
#define d(i) c[i].d
using namespace std;
int n, a, b;
struct game{
	int h, d;
};
game c[N];
bool cmp(game a, game b){
	return a.h - a.d > b.h - b.d;
}
int main(){
	scanf("%d%d%d", &n, &a, &b);
	b = min(b, n);
	for(int i = 0 ; i < n ; i++)
	    scanf("%d%d", &h(i), &d(i));
	sort(c, c + n, cmp);
	ll ans = 0;
	for(int i = 0 ; i < n ; i++){
		if(i < b) ans += max(h(i), d(i));
		else ans += d(i);
	}
	if(b == 0){
		printf("%lld\n", ans);
		return 0;
	}
	ll base = (1LL << a), res = ans;
	for(int i = 0 ; i < n ; i++){
		res = ans;
		if(i < b){
			res -= max(h(i), d(i));
			res += h(i) * base;
			ans = max(ans, res);
		}
		else{
			res -= d(i);
			res += h(i) * base;
			res -= max(h(b - 1), d(b - 1));
			res += d(b - 1);
			ans = max(ans, res);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
