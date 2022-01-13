#include <cstdio>

#define N 1010
using namespace std;
char a[N], b[N];
int n, m;
int s[N];
int q, l, r;
int main(){
	scanf("%d%d%d", &n, &m, &q);
	scanf("%s%s", a + 1, b);
	for(int i = 1 ; i <= n - m + 1 ; i++){
		int f = 1;
		for(int j = 0 ; j < m ; j++)
			if(a[i + j] != b[j]){
				f = 0;
				break;
			}
		if(f) s[i] = s[i - 1] + 1;
		else s[i] = s[i - 1];
	}
	while(q--){
		scanf("%d%d", &l, &r);
		if(r - l + 1 < m){
			puts("0");
			continue;
		}
		printf("%d\n", s[r - m + 1] - s[l - 1]);
	}
	return 0;
}
