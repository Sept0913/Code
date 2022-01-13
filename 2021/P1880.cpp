#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 220
using namespace std;
int a[N], sum[N];
int mn[N][N], mx[N][N];
int n;
int main(){
	memset(mn, 0x3f, sizeof(mn));
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for(int i = 1 ; i <= 2 * n ; i++){
		sum[i] = sum[i - 1] + a[i];
		mn[i][i] = 0;
	}
	for(int len = 2 ; len <= n ; len++){
		for(int l = 1 ; l <= 2 * n - len + 1 ; l++){
			int r = l + len - 1;
			int s = (sum[r] - sum[l - 1]);
			for(int k = l ; k < r ; k++){
				mn[l][r] = min(mn[l][r], mn[l][k] + mn[k + 1][r]);
				mx[l][r] = max(mx[l][r], mx[l][k] + mx[k + 1][r]);
			}
			mn[l][r] += s, mx[l][r] += s;
		}
	}
	int m1 = 1e9, m2 = 0;
	for(int i = 1 ; i <= n ; i++){
		m1 = min(mn[i][i + n - 1], m1);
		m2 = max(mx[i][i + n - 1], m2);
	}
	printf("%d\n%d\n", m1, m2);
	return 0;
}
