#include <cstdio>

#define N 1000010
using namespace std;
int k, n;
struct Node{
	int ind, num;
};
Node p[N];
int a[N];
int l = 0, r = 1;
inline int rd();
int main(){
	n = rd(), k = rd();
	for(int i = 0 ; i < n ; i++) a[i] = rd();
	for(int i = 0 ; i < n ; i++){
		int tmp = a[i];
		if(k == 1){
			printf("%d ", tmp);
			continue;
		}
		if(p[l].ind + k <= i) l++;
		while(l <= r && p[r].num <= tmp)
		    r--;
		r++;
		p[r].num = tmp;
		p[r].ind = i;
		if(i >= k - 1) printf("%d\n", p[l].num);
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
