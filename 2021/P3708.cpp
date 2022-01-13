#include <cstdio>

#define N 1000010
using namespace std;
int n;
long long sum[N], ans[N] = {1, 1};
int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++)
	    for(int j = i ; j <= n ; j += i)
	        sum[j] += i;
	for(int i = 2 ; i <= n ; i++) ans[i] = ans[i - 1] + sum[i];
	for(int i = 1 ; i <= n ; i++)
	    printf("%lld ", (long long)n * (long long)i - ans[i]);
	return 0;
}
