#include <cstdio>

#define N 100010
using namespace std;
int a[N], s[N], ans[N];
int n, t = 0;
inline int rd();
int main(){
	n = rd();
	for(int i = 0 ; i < n ; i++) a[i] = rd();
	for(int i = n - 1 ; i >= 0 ; i--){
		while(a[s[t]] <= a[i] && t > 0) t--;
		if(t > 0) ans[i] = s[t] + 1;
		else ans[i] = 0;
		t++;
		s[t] = i;
	}
	for(int i = 0 ; i < n ; i++) printf("%d\n", ans[i]);
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
