#include <cstdio>
#include <algorithm>

#define N 1000010
using namespace std;
int a[N], s[N], ans[N] = {0}, v[N];
int n, t = 0;
inline int rd();
int main(){
	n = rd();
	for(int i = 1 ; i <= n ; i++)
	    a[i] = rd(), v[i] = rd();
	for(int i = 1 ; i <= n ; i++){
		while(t && a[s[t]] < a[i])
		    ans[i] += v[s[t]], t--;
		ans[s[t]] += v[i];
		t++;
		s[t] = i;
	}
	int Ans = 0;
	for(int i = 1 ; i <= n ; i++)
	    Ans = max(Ans, ans[i]);
	printf("%d", Ans);
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
