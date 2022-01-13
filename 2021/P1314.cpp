#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;
int pn[200010], pv[200010];
int n, m, sum, s, ys;
int w[200010], v[200010], l[200010], r[200010];
bool ck(int W){
	memset(pn, 0, sizeof(pn));
	memset(pv, 0, sizeof(pv));
	ys = 0, sum = 0;
	for(int i = 1 ; i <= n ; i++){
		if(w[i] >= W) pn[i] = pn[i - 1] + 1, pv[i] = pv[i - 1] + v[i];
		else pn[i] = pn[i - 1], pv[i] = pv[i - 1];
	}
	for(int i = 1 ; i <= m ; i++)
	    ys += (pn[r[i]] - pn[l[i] - 1]) * (pv[r[i]] - pv[l[i] - 1]);
	sum = llabs(ys - s);
	return ys > s;
}
signed main(){
	scanf("%lld%lld%lld", &n, &m, &s);
	int mx = -1, mn = 2147483647;
	for(int i = 1 ; i <= n ; i++){
		scanf("%lld%lld", &w[i], &v[i]);
		mx = max(mx, w[i]);
		mn = min(mn, w[i]);
	}
	for(int i = 1 ; i <= m ; i++) scanf("%lld%lld", &l[i], &r[i]);
	int L = mn - 1, R = mx + 2, M;
	int ans = 0x3f3f3f3f3f3f3f3f;
	while(L <= R){
		M = (L + R) >> 1;
		if(ck(M)) L = M + 1;
		else R = M - 1;
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
