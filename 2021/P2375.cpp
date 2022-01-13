#include <cstdio>
#include <cstring>

#define mod 1000000007
#define N 1000010
#define int long long
using namespace std;
int fail[N], q[N];
char p[N];
int n, t;
void Sol(){
	memset(fail, 0, sizeof(fail));
	memset(fail, 0, sizeof(q));
	scanf("%s", p + 1);
	n = strlen(p + 1);
	int j = 0;
	q[1] = 1;
	for(int i = 2 ; i <= n ; i++){
		while(p[i] != p[j + 1] && j > 0) j = fail[j];
		if(p[i] == p[j + 1]) j++;
		fail[i] = j, q[i] = q[j] + 1;
	}
	j = 0;
	int ans = 1;
	for(int i = 2 ; i <= n ; i++){
		while(p[j + 1] != p[i] && j) j = fail[j];
		if(p[i] == p[j + 1]) j++;
		while(2 * j > i) j = fail[j];
		ans = ans * (q[j] + 1) % mod;
	}
	printf("%lld\n", ans % mod);
}
signed main(){
	scanf("%lld", &t);
	while(t--)
	   Sol();
	return 0;
}
