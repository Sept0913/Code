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
		add(i, a[i] - a[i - 1]);
	}
	for(int i = 0 ; i < m ; i++){
		int op, x, y, k;
		scanf("%d", &op);
		if(op == 1){
			scanf("%d%d%d", &x, &y, &k);
			add(x, k);
			add(y + 1, -k);
		}
		else{
			scanf("%d", &x);
			printf("%d\n", query(x));
		}
	}
	return 0;
}
