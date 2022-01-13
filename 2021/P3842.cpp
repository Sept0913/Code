#include <cstdio>
#include <algorithm>

#define N 20010
#define d(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))
using namespace std;
int f[N][2], l[N], r[N];
int n;
int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++)
	    scanf("%d%d", &l[i], &r[i]);
	f[1][0] = d(1, r[1]) + d(l[1], r[1]), f[1][1] = d(1, r[1]);
	for(int i = 2 ; i <= n ; i++){
		f[i][0] = min(f[i-1][0] + d(l[i-1], r[i]), f[i-1][1] + d(r[i-1], r[i])) + d(l[i], r[i]) + 1;
		f[i][1] = min(f[i-1][0] + d(l[i-1], l[i]), f[i-1][1] + d(r[i-1], l[i])) + d(l[i], r[i]) + 1;
	}
	printf("%d\n", min(f[n][0] + d(l[n], n), f[n][1] + d(r[n], n)));
	return 0;
}
