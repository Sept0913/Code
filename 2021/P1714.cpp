/*
Huge thank to @syf2008 for his data! 
10 8
892 -448 -431 86 -41 190 -46 -104 433 1
*/
#include <cstdio>
#include <algorithm>

#define N 500010
using namespace std;
int m, n;
struct Node{
	int ind, num;
};
Node q[N];
int a[N], u[N];
int l = 1, r = 0, ans = -1000000010;
inline int rd();
int main(){
	n = rd(), m = rd();
	for(int i = 0 ; i < n ; i++) u[i] = rd();
	a[0] = u[0];
	for(int i = 1 ; i < n ; i++) a[i] = a[i - 1] + u[i];
	for(int i = 0 ; i < n ; i++){
		int tmp = i ? a[i - 1] : 0;
		if(q[l].ind + m <= i) l++;
		while(l <= r && q[r].num >= tmp)
			r--;
		r++;
		q[r].num = tmp;
		q[r].ind = i;
		ans = max(a[i] - q[l].num, ans);
	}
	printf("%d\n", ans);
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
