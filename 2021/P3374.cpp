#include <cstdio>

#define N 500010
using namespace std;
int a[N], c[N];
int n, m;
void add(int x, int y){
	for( ; x <= n ; x += x & -x) c[x] += y;
}
int query(int x){
	int ans = 0;
	for( ; x ; x -= x & -x) ans += c[x];
	return ans;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	for(int i = 0 ; i < m ; i++){
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1)	add(l, r);
		else printf("%d\n", query(r) - query(l - 1));
	}
	return 0;
}
