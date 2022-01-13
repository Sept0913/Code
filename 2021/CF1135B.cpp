#include <cstdio>
#include <algorithm>

#define N 110
#define M 110
using namespace std;
int n, m, h;
int a[M], b[N], c[N][M];
int main(){
	scanf("%d%d%d", &n, &m, &h);
	for(int i = 0 ; i < m ; i++) scanf("%d", &a[i]);
	for(int i = 0 ; i < n ; i++) scanf("%d", &b[i]);
	for(int i = 0 ; i < n ; i++, puts(""))
	    for(int j = 0 ; j < m ; j++){
	        scanf("%d", &c[i][j]);
	        printf("%d ", c[i][j] ? min(a[j], b[i]) : 0);
		}
	return 0;
}
