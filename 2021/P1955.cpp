#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 1000010
using namespace std;
int t, n;
int a[3 * N], len, fa[N];
struct node{
	int x, y, e;
};
node b[N];
bool cmp(node a, node b){
	return a.e > b.e;
}
void init(int k){
	for(int i = 1 ; i <= k ; i++) fa[i] = i;
}
int Find(int a){
	if(a == fa[a]) return a;
	return fa[a] = Find(fa[a]);
}
void Make(int a, int b){
	int t1 = Find(a), t2 = Find(b);
    if(t1 != t2) fa[t1] = t2;
}
void sol(){
	memset(fa, 0, sizeof(fa));
	len = -1;
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].e);
		a[++len] = b[i].x;
		a[++len] = b[i].y;
	}
	sort(a, a + len);
	len = unique(a, a + len) - a;
	init(len);
	for(int i = 1 ; i <= n ; i++){
		b[i].x = lower_bound(a, a + len, b[i].x) - a;
		b[i].y = lower_bound(a, a + len, b[i].y) - a;
	}
	sort(b + 1, b + n + 1, cmp);
	for(int i = 1 ; i <= n ; i++){
		if(b[i].e){
			Make(Find(b[i].x), Find(b[i].y));
		}
		else{
			int t1 = Find(b[i].x), t2 = Find(b[i].y);
			if(t1 == t2){
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
}
int main(){
	scanf("%d", &t);
	while(t--) sol();
	return 0;
}
