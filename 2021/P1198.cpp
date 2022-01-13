#include <cstdio>
#include <algorithm>

#define N 800010
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
	v[k] = max(v[k << 1], v[k << 1 | 1]);
}
void update(int k){
	v[k] = max(v[k << 1], v[k << 1 | 1]);
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
	int ans = 0;
	int m = l + r >> 1;
	if(ql <= m)
	    ans = max(ans, query(l, m, ql, min(qr, m), k << 1));
	if(qr > m)
	    ans = max(ans, query(m + 1, r, max(ql, m + 1), qr, k << 1 | 1));
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
int n, q, m;
int main(){
	scanf("%d%d", &q, &m);
	build(1, 200000, 1);
	int t = 0;
	while(q--){
		char op;
		scanf("\n%c", &op);
		if(op == 'A'){
			int d;
			scanf("%d", &d);
			n++;
			d = (d + t) % m;
			modify(1, 200000, n, n, 1, d);
		}
		else{
			int l;
			scanf("%d", &l);
			t = query(1, 200000, n - l + 1, n, 1);
			printf("%d\n", t);
		}
	}
	return 0;
}
