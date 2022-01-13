#include <cstdio>
#include <algorithm>

#define N 20 
using namespace std;
int v[N][N];
int dp[N][N][N][N];
int n;
int main(){
	scanf("%d", &n);
	int x, y, u;
	while(1){
		scanf("%d%d%d", &x, &y, &u);
		if(!x && !y && !u) break;
		v[x][y] = u;
	}
	for(int a = 1 ; a <= n ; a++)
	    for(int b = 1 ; b <= n ; b++)
	        for(int c = 1 ; c <= n ; c++){
	        	int d = a + b - c;
	        	if(d < 1 || d > n) continue;
	        	dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c - 1][d]);
	            dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c - 1][d]);
	            dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d - 1]);
	            dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d - 1]);
	            dp[a][b][c][d] += (v[a][b] + v[c][d]);
	            if(a == c && b == d) dp[a][b][c][d] -= v[a][b];
			}
	printf("%d\n", dp[n][n][n][n]);
	return 0;
}
