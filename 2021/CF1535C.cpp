#include <cstdio>
#include <algorithm>
#include <cstring>

#define ll long long
#define N 200010
using namespace std;
char s[N];
ll dp[N][2];
void Sol(){
	scanf("%s", s);
	int n = strlen(s);
	ll ans = 0;
	memset(dp, 0, sizeof(dp));
	if(s[0] == '?') dp[0][0] = dp[0][1] = 1;
	else dp[0][s[0] - '0'] = 1;
	for(int i = 1 ; i < n ; i++){
		if(s[i] == '1') dp[i][1] = dp[i - 1][0] + 1;
		else if(s[i] == '0') dp[i][0] = dp[i - 1][1] + 1;
		else dp[i][1] = dp[i - 1][0] + 1, dp[i][0] = dp[i - 1][1] + 1;
	}
	for(int i = 0 ; i < n ; i++)
	    ans += max(dp[i][0], dp[i][1]);
	printf("%lld\n", ans);
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--)
	    Sol();
	return 0;
}
