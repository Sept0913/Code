#include <cstdio>
#include <cstring>

#define N 1000010
using namespace std;
int a[N];
int p[N], cnt;
int n, m;
int l = 0, ansl = 0, ansr = N;
inline int rd();
int main(){
	n = rd(), m = rd();
	memset(p, -1, sizeof(p));
	for(int i = 0 ; i < n ; i++){
		a[i] = rd();
		if(p[a[i]] == -1) cnt++;
		p[a[i]] = i;
		while(l != i && l < p[a[l]]) l++;
		if(cnt == m && i - l + 1 < ansr - ansl + 1)
		    ansl = l, ansr = i;
	}
	printf("%d %d", ansl + 1, ansr + 1);
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
