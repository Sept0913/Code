#include <cstdio>
#include <algorithm>

using namespace std;
inline int rd();
struct node{
	int x, y, z;
};
bool cmp(node a, node b){
	return a.x < b.x;
}
node p[1000010];
int ans = 0;
int r, g;
int main(){
	r = rd(), g = rd();
	for(int i = 1 ; i * i <= r ; i++){
		if(r % i == 0){
			if(g % i == 0){
				p[ans].x = i;
				p[ans].y = r / i;
				p[ans].z = g / i;
				ans++;
			}
			if(g % (r / i) == 0 && i * i != r){
				p[ans].x = r / i;
				p[ans].y = i;
				p[ans].z = g / (r / i);
				ans++;
			}
		}
	}
	sort(p, p + ans, cmp);
	for(int i = 0 ; i < ans ; i++)
	    printf("%d %d %d\n", p[i].x, p[i].y, p[i].z);
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
