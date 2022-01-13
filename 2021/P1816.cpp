#include <cstdio>
#include <algorithm>

#define N 400010
using namespace std;
int v[N], a[N], lazy[N];
void build(int l, int r, int k){
	if(l == r){
		v[k] = a[l];
		return;
	}
	int m = l + r >> 1;
	build(l, m, k << 1);
	build(m + 1, r, k << 1 | 1);
	v[k] = min(v[k << 1], v[k << 1 | 1]);
}
void update(int k){
	v[k] = min(v[k << 1], v[k << 1 | 1]);
}
void pushdown(int k){
	v[k << 1] += lazy[k];
	lazy[k << 1] += lazy[k];
	v[k << 1 | 1] += lazy[k];
	lazy[k << 1 | 1] += lazy[k];
}
int query(int l, int r, int ql, int qr, int k){
	if(l == ql && r == qr)
		return v[k];
	pushdown(k);
	int ans = INT_MAX;
	int m = l + r >> 1;
	if(ql <= m)
	    ans = min(ans, query(l, m, ql, min(qr, m), k << 1));
	if(qr > m)
	    ans = min(ans, query(m + 1, r, max(ql, m + 1), qr, k << 1 | 1));
	return ans;
}
void modify(int l, int r, int ql, int qr, int k, int y){
	if(l == ql && r == qr){
		v[k] += y;
		lazy[k] += y;
		return;
	}
	pushdown(k);
	int m = l + r >> 1;
	if(ql <= m)
	    modify(l, m, ql, min(qr, m), k << 1, y);
	if(qr > m)
	    modify(m + 1, r, max(ql, m + 1), qr, k << 1 | 1, y);
	update(k);
}
int n, q;
int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1 ; i <= n ; i++)
	    scanf("%d", &a[i]);
	build(1, n, 1);
	while(q--){
		int op, y, l, r;
		scanf("%d%d", &l, &r);
		printf("%d ", query(1, n, l, r, 1));
	}
	return 0;
}
