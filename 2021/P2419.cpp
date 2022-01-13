#include <cstdio>

#define N 110
using namespace std;
int n, m;
bool e[N][N];
int ans = 0;
void floyed(){
	for(int k = 1 ; k <= n ; k++)
	    for(int i = 1 ; i <= n ; i++)
	        for(int j = 1 ; j <= n ; j++)
	            e[i][j] |= (e[i][k] & e[k][j]);
}
int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		int u, v;
		scanf("%d%d", &u, &v);
		e[u][v] = 1;
	}
	floyed();
	for(int i = 1 ; i <= n ; i++){
		bool f = 1;
		for(int j = 1 ; j <= n ; j++){
			if(i != j && !e[i][j] && !e[j][i]){
				f = 0;
				break;
			}
		}
		ans += f;
	}
	printf("%d\n", ans);
	return 0;
}
