#include <cstdio>
#include <cmath>

#define int long long
#define N 1010
using namespace std;
int squ(int x){
	return x * x;
}
int n, h, r;
bool d(int x1, int x2, int y1, int y2, int z1, int z2){
	int k = squ(x1 - x2) + squ(y1 - y2) + squ(z1 - z2);
	return k <= 4 * r * r;
}
int fa[N];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y){
	int t1 = find(x), t2 = find(y);
	if(t1 != t2) fa[t1] = t2;
}
int x[N], y[N], z[N];
void Sol(){
	for(int i = 0 ; i <= N ; i++) fa[i] = i;
	scanf("%lld%lld%lld", &n, &h, &r);
	for(int i = 1 ; i <= n ; i++)
	    scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
	for(int i = 1 ; i <= n ; i++){
		if(z[i] <= r) merge(0, i);
		if(z[i] + r >= h) merge(i, n + 1);
		for(int j = i + 1 ; j <= n ; j++){
			if(d(x[i], x[j], y[i], y[j], z[i], z[j]))
			    merge(i, j);
		}
	}
	if(find(0) == find(n + 1)) puts("Yes");
	else puts("No");
}
signed main(){
	int T;
	scanf("%lld", &T);
	while(T--)
	    Sol();
	return 0;
}
