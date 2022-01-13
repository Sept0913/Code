#include <cstdio>
#include <algorithm>

#define N 310
using namespace std;
int f[N][N], a[N];
int n, ans = 0;
int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &a[i]);
		f[i][i] = a[i];
		ans = max(ans, a[i]);
	}
	for(int l = 2 ; l <= n ; l++)
		for(int i = 1 ; i <= n - l + 1 ; i++){
			int j = i + l - 1;
			for(int k = i ; k < j ; k++)
			    if(f[i][k] == f[k + 1][j] && f[i][k])
			        f[i][j] = max(f[i][j], f[i][k] + 1),
			        ans = max(ans, f[i][j]);
		}
	printf("%d\n", ans);
	return 0;
}
