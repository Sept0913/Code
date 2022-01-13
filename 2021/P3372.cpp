#include <cstdio>
#include <algorithm>

#define ll long long
#define N 400010
using namespace std;
int n, q;
ll lazy[N], a[N], v[N];
void update(int k){
	v[k] = v[k << 1] + v[k << 1 | 1];
}
void one_push(int l, int r, int k, ll d){
	v[k] += (r - l + 1) * d;
	lazy[k] += d;
}
void pushdown(int l, int r, int k){
	ll d = lazy[k];
	int m = l + r >> 1;
	one_push(l, m, k << 1, d);
	one_push(m + 1, r, k << 1 | 1, d);
	lazy[k] = 0;
}
void build(int l, int r, int k){
	if(l == r){
		v[k] = a[l];
		return;
	}
	int m = l + r >> 1;
	build(l, m, k << 1);
	build(m + 1, r, k << 1 | 1);
	update(k);
}
ll query(int l, int r, int ql, int qr, int k){
	if(l == ql && r == qr) return v[k];
	pushdown(l, r, k);
	int m = l + r >> 1;
	ll ans = 0;
	if(ql <= m)
	    ans += query(l, m, ql, min(qr, m), k << 1);
	if(qr > m)
	    ans += query(m + 1, r, max(ql, m + 1), qr, k << 1 | 1);
	return ans;
}
void modify(int l, int r, int ql, int qr, int k, int y){
	if(l == ql && r == qr){
		v[k] += (r - l + 1) * y;
		lazy[k] += y;
		return;
	}
	pushdown(l, r, k);
	int m = l + r >> 1;
	if(ql <= m)
	    modify(l, m, ql, min(qr, m), k << 1, y);
	if(qr > m)
	    modify(m + 1, r, max(ql, m + 1), qr, k << 1 | 1, y);
	update(k);
}
int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1 ; i <= n ; i++) scanf("%lld", &a[i]);
	build(1, n, 1);
	while(q--){
		int op, l, r;
		ll d;
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1){
			scanf("%lld", &d);
			modify(1, n, l, r, 1, d);
		}
		else
		    printf("%lld\n", query(1, n, l, r, 1));
	}
	return 0;
}
