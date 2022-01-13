#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 100010
#define mod 1000000007
using namespace std;
int n;
int a[N];
int dp[N];
int fac[N], len;
long long ans = 0;
bool cmp(int a, int b){
	return a > b;
}
void calc(int x){
	len = -1;
	for(int i = 1 ; i * i <= x ; i++){
		if(x % i == 0){
			fac[++len] = i;
			if(i * i != x) fac[++len] = x / i;
		}
	}
	sort(fac, fac + len + 1, cmp);
}
int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++) scanf("%d", &a[i]);
	dp[0] = 1;
	for(int i = 1 ; i <= n ; i++){
		calc(a[i]);
		for(int j = 0 ; j <= len ; j++)
		    if(fac[j] <= i)
			    dp[fac[j]] = (dp[fac[j] - 1] + dp[fac[j]]) % mod;
	}
	for(int i = 1 ; i <= n ; i++)
	    ans = (ans + dp[i]) % mod;
	printf("%lld\n", ans);
	return 0;
}
