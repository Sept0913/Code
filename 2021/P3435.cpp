#include <cstdio>
#include <cstring>

#define int long long
#define N 1000010
using namespace std;
int fail[N];
char s[N], p[N];
int n;
signed main(){
	scanf("%lld%s", &n, p + 1);
	int j = 0;
	for(int i = 2 ; i <= n ; i++){
		while(p[i] != p[j + 1] && j > 0) j = fail[j];
		if(p[i] == p[j + 1]) j++, fail[i] = j;
	}
	j = 2;
	int ans = 0;
	for(int i = 2 ; i <= n ; i++){
		j = i;
		while(fail[j]) j = fail[j];
		if(fail[i]) fail[i] = j;
		ans += (i - j);
	}
	printf("%lld\n", ans);
	return 0;
}
