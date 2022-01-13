#include <cstdio>
#include <cstring>

#define MOD 1000000007
using namespace std;
char s[110];
int t, n;
long long dp[110][10010];
void sol(){
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	scanf("%s", s);
	n = strlen(s);
	int sum = 0;
	for(int i = 0 ; i < n ; i++) sum += (s[i] - 'a' + 1);
	for(int x = 1 ; x <= n ; x++){
		for(int y = 1 ; y <= sum ; y++){
			int k = y > 26 ? 26 : y;
			for(int z = 1 ; z <= k ; z++)
			    dp[x][y] += dp[x - 1][y - z];
			dp[x][y] %= MOD;
		}
	}
	printf("%lld\n", dp[n][sum] - 1);
}
int main(){
	scanf("%d", &t);
	while(t--)
	    sol();
	return 0;
}
