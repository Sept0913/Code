#include <cstdio>

#define N 200010
using namespace std;
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
int x, a[N], sum = 0;
int n;
int ans = 0;
void Sol(){
	sum = 0, ans = 0;
	n = rd();
	for(int i = 0 ; i < n ; i++)
	    a[i] = rd(), sum += a[i];
	if(sum % n != 0){
		puts("-1");
		return;
	}
	x = sum / n;
	for(int i = 0 ; i < n ; i++)
	    ans += (a[i] > x);
	printf("%d\n", ans);
}
int main(){
	int T = rd();
	while(T--)
	    Sol();
	return 0;
}
