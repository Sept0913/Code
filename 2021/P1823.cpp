/*
Huge thank to @Virtualtan for his data! 
6
10 10 2 10 9 9
*/
#include <cstdio>
#include <algorithm>

#define int long long

#define N 500010
using namespace std;
struct Node{
	int h, n;
};
int a[N];
Node s[N];
int n, t = 1;
int ans = 0;
inline int rd();
signed main(){
	n = rd();
	for(int i = 0 ; i < n ; i++)
		a[i] = rd();
	s[0].h = a[0], s[0].n = 1;
	for(int i = 0 ; i < n ; i++){
		while(t > 0 && s[t].h < a[i])
		    ans += s[t].n, t--;
		if(t > 0 && s[t].h == a[i]){
			ans += s[t].n;
			if(t > 1) ans++;
			s[t].n++;
		}
		else if(!t){
			t++;
			s[t].h = a[i], s[t].n = 1;
		}
		else{
		    ans++, t++;
			s[t].h = a[i], s[t].n = 1;	
		}
	}
	printf("%lld", ans);
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
