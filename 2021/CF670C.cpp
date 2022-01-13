#include <cstdio>
#include <algorithm>

#define N 600010
using namespace std;
int a[N], b[N], c[N];
int all[N];
int len = -1;
int num[N], ax, ay, ai = 1;
int query(int k){
	return lower_bound(all, all + len, k) - all;
}
int n, m;
int main(){
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		all[++len] = a[i];
	}
	scanf("%d", &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &b[i]);
		all[++len] = b[i];
	}
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &c[i]);
		all[++len] = c[i];
	}
	sort(all, all + len);
	len = unique(all, all + len) - all;
	for(int i = 0 ; i < n ; i++) a[i] = query(a[i]), num[a[i]]++;
	for(int i = 0 ; i < m ; i++){
		b[i] = query(b[i]), c[i] = query(c[i]);
		int x = num[b[i]], y = num[c[i]];
		if(x > ax || x == ax && y > ay)
		    ai = i + 1, ax = x, ay = y;
	}
	printf("%d\n", ai);
	return 0;
} 
