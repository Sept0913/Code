#include <cstdio>
#include <set>

#define ll long long
#define M 100010
#define INF 100000
using namespace std;
ll b, q, l, m;
ll a[M];
ll ans = 0, c = 0;
set <int> s;
int main(){
	scanf("%lld%lld%lld%lld", &b, &q, &l, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%lld", &a[i]);
		s.insert(a[i]);
	}
	while(b <= l && -b <= l){
		ans += (s.find(b) == s.end());
		c++;
		b *= q;
		if(c == INF){
			ans = (ans != 0 && ans != 1) ? INF : ans;
			break;
		}
	}
	if(ans == INF) puts("inf");
	else printf("%lld\n", ans);
	return 0;
}
