#include <cstdio>

#define N 1000010
using namespace std;
int k, n;
struct Node{
	int ind, num;
};
Node p[N], q[N];
int a[N];
int l = 1, r = 0;
inline int rd();
int main(){
	n = rd(), k = rd();
	for(int i = 0 ; i < n ; i++) a[i] = rd();
	for(int i = 0 ; i < n ; i++){
		int tmp = a[i];
		if(q[l].ind + k <= i) l++;
		while(l <= r && q[r].num >= tmp)
		    r--;
		r++;
		q[r].num = tmp;
		q[r].ind = i;
		if(i >= k - 1) printf("%d ", q[l].num);
	}
	puts("");
	for(int i = 0 ; i < n ; i++){
		int tmp = a[i];
		if(p[l].ind + k <= i) l++;
		while(l <= r && p[r].num <= tmp)
		    r--;
		r++;
		p[r].num = tmp;
		p[r].ind = i;
		if(i >= k - 1) printf("%d ", p[l].num);
	}
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
