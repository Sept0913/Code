#include <cstdio>
#include <vector>
#include <algorithm>

#define N 100010
using namespace std;
vector <int> s[N];
int fa;
int n;
int siz[N];
void dfs(int u){
	int len = s[u].size();
	int ans = 0;
	if(len == 0){
		siz[u] = 1;
		return;
	}
	for(int i = 0 ; i < len ; i++){
		dfs(s[u][i]);
		ans += siz[s[u][i]];
	}
	siz[u] = ans;
}
int main(){
	scanf("%d", &n);
	for(int i = 2 ; i <= n ; i++){
		scanf("%d", &fa);
		s[fa].push_back(i);
	}
	dfs(1);
	sort(siz + 1, siz + n + 1);
	for(int i = 1 ; i <= n ; i++) printf("%d ", siz[i]);
	return 0;
}
