#include <cstdio>
#include <algorithm>

using namespace std;
int b, x, n, now = 0, w;
int lig[100010];
int ans = 0;
int ans2 = 0;
int main(){
	scanf("%d%d", &n, &w);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &x, &b);
		now = max(now, x);
		lig[x] += b;
	}
	for(int i = 0 ; i < w - 1 ; i++) ans += lig[i], ans2 += lig[i];
	for(int i = w - 1 ; i < now ; i++){
		ans2 = ans2 - lig[i - w] + lig[i];
		ans = max(ans, ans2);
	}
	printf("%d", ans);
	return 0;
}
