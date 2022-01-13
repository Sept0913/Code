#include <cstdio>
#include <algorithm>

using namespace std;
inline int rd();
int a[110], b[110];
int n, m, I1, I2;
int abs(int x){return x > 0 ? x : -x;}
void Sol(){
	n = rd();
	for(int i = 0 ; i < n ; i++) a[i] = rd();
	m = rd();
	for(int i = 0 ; i < m ; i++) b[i] = rd();
	sort(a, a + n); sort(b, b + m);
	I1 = 0, I2 = 0;
	int ans = 0;
	while(I1 < n && I2 < m){
		if(abs(a[I1] - b[I2]) <= 1){
		    ans++, I1++, I2++;
		}
		else if(a[I1] < b[I2]) I1++;
		else I2++;
	}
	printf("%d\n", ans);
}
int T = 1;
int main(){
	//T = rd();
	while(T--) Sol();
	return 0;
}
inline int rd(){
	char c;
	bool flag = false;
	while((c = getchar()) < '0' || c > '9')
	    if(c == '-') flag = true;
	int res = c - '0';
	while((c = getchar()) >= '0' && c <= '9')
	    res = (res << 3) + (res << 1) + c - '0';
	return flag ? -res : res;
}
