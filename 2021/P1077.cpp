#include <cstdio>
#include <algorithm>

#define N 110
#define p 1000007
using namespace std;
int f[N][N], a[N];
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; i++) scanf("%d", &a[i]);
	f[0][0] = 1;
	for(int i = 1 ; i <= n ; i++)
	    for(int j = 0 ; j <= m ; j++)
	        for(int k = 0 ; k <= min(a[i], j) ; k++)
	            f[i][j] = (f[i][j] + f[i - 1][j - k]) % p;
	printf("%d\n", f[n][m]);
	return 0;
}
