#include <cstdio>

#define N 5010
using namespace std;
int n, k, a[N], q, x;
void Query(){
	scanf("%d", &x);
	int ans = 0;
	for(int i = n - 1 ; i >= 0 ; i++){
		if(a[i] > x) continue;
		ans += (x / a[i]);
		x -= ((x / a[i]) * a[i]);
		if(ans > k) break;
		if(!x){
			printf("%d\n", ans);
			return;
		}
	}
	puts("-1");
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0 ; i < n ; i++) scanf("%d", &a[i]);
	scanf("%d", &q);
	while(q--)
		Query();
	return 0;
}
