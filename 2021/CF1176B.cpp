#include <cstdio>
#include <algorithm>
#include <cmath>

#define N 110
using namespace std;
int n, a[N], b[3];
void Sol(){
	b[0] = b[1] = b[2] = 0;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		b[a[i] % 3]++;
	}
	int mn = min(b[1], b[2]);
	int mx = max(b[1], b[2]);
	printf("%d\n", b[0] + mn + (mx - mn) / 3);
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--)
	    Sol();
	return 0;
}
