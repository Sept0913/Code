#include <cstdio>

#define N 2000010
#define int long long
using namespace std;
int k, n;
struct Node{
	int ind, num;
};
Node q[N];
int a[N], u[N];
int l = 1, r = 0, ans = 0;
inline int rd();
signed main(){
	n = rd();
	for(int i = 0 ; i < n ; i++) u[i] = rd(), u[i + n] = u[i];
	a[0] = u[0];
	for(int i = 1 ; i < 2 * n ; i++) a[i] = a[i - 1] + u[i];
	for(int i = 0 ; i < 2 * n ; i++){
		int tmp = a[i];
		if(q[l].ind + n <= i) l++;
		while(l <= r && q[r].num >= tmp)
		    r--;
		r++;
		q[r].num = tmp;
		q[r].ind = i;
		if(i >= n){
			if(q[l].num - a[i - n] >= 0) ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
inline int rd(){
	char c;
	bool flag = 0;
	while((c = getchar()) < '0' || c > '9')
	    if(c == '-') flag = 1;
	int res = c - '0';
	while((c = getchar()) >= '0' && c <= '9')
	    res = (res << 3) + (res << 1) + c - '0';
	return flag ? -res : res;
}
