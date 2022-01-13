#include <cstdio>
#include <algorithm>

#define N 410
#define INF 1e6 + 10
using namespace std;
int h[N][N];
void init(){
	for(int i = 1 ; i < N ; i++)
	    for(int j = 1 ; j < N ; j++)
	        h[i][j] = INF;
}
int n, m, t;
void floyed(){
	for(int k = 1 ; k <= n ; k++)
	    for(int i = 1 ; i <= n ; i++)
	        for(int j = 1 ; j <= n ; j++)
	            h[i][j] = min(h[i][j], max(h[i][k], h[k][j]));
}
int main(){
	init();
	scanf("%d%d%d", &n, &m, &t);
	while(m--){
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		h[u][v] = d;
	}
	floyed();
	while(t--){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", h[a][b] == INF ? -1 : h[a][b]);
	}
	return 0;
}
