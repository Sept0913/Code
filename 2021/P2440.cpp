#include <cstdio>

#define N 100010 
using namespace std;
int n, k;
int len[N];
int l = 0, r = 1e8 + 10;
inline int rd();
bool check(int ll){
	int sum = 0;
	for(int i = 0 ; i < n ; i++) sum += len[i] / ll;
	return sum >= k;
}
int main(){
	n = rd(), k = rd();
	for(int i = 0 ; i < n ; i++) len[i] = rd();
	while(l < r - 1){
		int mid = l + r >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%d\n", l);
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
