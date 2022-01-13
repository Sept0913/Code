#include <cstdio>
#include <map>

#define N 10010
using namespace std;
int n, a[N], d[N], c[N], h, k, m;
map < pair <int, int>, bool > M;
int main(){
	scanf("%d%d%d%d", &n, &k, &h, &m);
	while(m--){
		int a, b;
		scanf("%d%d", &a, &b);
		if(a > b) swap(a, b);
		if(M[make_pair(a, b)]) continue;
		d[a + 1]--, d[b]++;
		M[make_pair(a, b)] = 1;
	}
	for(int i = 1 ; i <= n ; i++){
		c[i] = c[i - 1] + d[i];
		printf("%d\n", h + c[i]);
	}
	return 0;
}
