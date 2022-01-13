#include <cstdio>

#define int long long
using namespace std;
int dp[30][30], f[30][30], a, b, c, d;
int dx[9] = {2, 1, -1, -2, -2, -1, 1, 2, 0};
int dy[9] = {1, 2, 2, 1, -1, -2, -2, -1, 0};
signed main(){
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	dp[0][0] = 1;
	for(int i = 0 ; i < 9 ; i++){
		int x = c + dx[i], y = d + dy[i];
		if(x >= 0 && x <= a && y >= 0 && y <= b) f[x][y] = 1;
	}
	int k = 0;
	while(!f[k][0] && k <= a)
		dp[k++][0] = 1;
	k = 0;
	while(!f[0][k] && k <= b){
		dp[0][k++] = 1;
	}
	for(int i = 1 ; i <= a ; i++){
		for(int j = 1 ; j <= b ; j++){
			if(f[i][j]) dp[i][j] = 0;
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	printf("%lld\n", dp[a][b]);
	return 0;
}
