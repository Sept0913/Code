#include <cstdio>
#include <algorithm>

using namespace std;
inline int rd();
int n, b[300010];
int ans = 0;
int m = 0;
int main(){
	n = rd();
	for(int i = 0 ; i < n ; i++) b[i] = rd();
	sort(b, b + n);
	for(int i = 0 ; i < n ; i++){
		b[i] += (n - i);
		m = max(m, b[i]);
	}
	for(int i = 0 ; i < n ; i++){
		if(b[i] + i >= m) ans++;
	}
	printf("%d", ans);
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
