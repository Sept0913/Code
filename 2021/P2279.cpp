#include <cstdio>
#include <vector>
#include <algorithm>

#define N 2021
#define INF 99999999
using namespace std;
vector <int> t[N];
int dp[N][5];
int n;
void dfs(int u){
	dp[u][4] = 1, dp[u][1] = 0, dp[u][0] = 0;
	int len = t[u].size();
	for(int i = 0 ; i < len ; i++){
		int v = t[u][i];
		dfs(v);
		dp[u][4] += dp[v][0];
		dp[u][1] += dp[v][2];
		dp[u][0] += dp[v][1];
	}
	if(!len) dp[u][2] = dp[u][3] = 1;
	else{
		dp[u][2] = dp[u][3] = INF;
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0 ; i < len ; i++){
			int v = t[u][i];
			cnt1 += dp[v][1];
			cnt2 += dp[v][2];
		}
		for(int i = 0 ; i < len ; i++){
			int v = t[u][i];
			dp[u][3] = min(cnt1 - dp[v][1] + dp[v][4], dp[u][3]);
			dp[u][2] = min(cnt2 - dp[v][2] + dp[v][3], dp[u][2]);
		}
	}
	for(int i = 3 ; i >= 0 ; i--)
	    dp[u][i] = min(dp[u][i + 1], dp[u][i]);
}
int main(){
	scanf("%d", &n);
	for(int i = 2 ; i <= n ; i++){
		int u;
		scanf("%d", &u);
		t[u].push_back(i);
	}
	dfs(1);
	printf("%d\n", dp[1][2]);
	return 0;
}
/* 
#include <cstdio>
#include <algorithm>

#define N 2021
using namespace std;
bool diz[N], dio[N], dit[N];
int fa[N], de[N], ind[N];
bool cmp(int a, int b){
	return de[a] > de[b];
}
bool check(int u, int op){
	if(op == 0) return (!diz[u]) && (!dio[u]) && (!dit[u]);
	if(op == 1) return (!diz[u]) && (!dio[u]);
	return !diz[u];
}
int n;
int ans = 0;
int main(){
	scanf("%d", &n);
	ind[1] = 1;
	for(int i = 2 ; i <= n ; i++){
		scanf("%d", &fa[i]);
		de[i] = de[fa[i]] + 1;
		ind[i] = i;
	}
	sort(ind + 1, ind + n + 1, cmp);
	for(int i = 1 ; i <= n ; i++){
		int u = ind[i], v = fa[u], w = fa[v], x = fa[w], y = fa[x];
		if(check(u, 0) && check(v, 1) && check(w, 2))
		    ans++, diz[w] = 1, dio[x] = 1, dit[y] = 1;
	}
	printf("%d\n", ans);
	return 0;
}
*/
