#include <cstdio>
#include <algorithm> 

#define N 100010
#define ll long long
using namespace std;
struct line{
	ll x, y;
};
line a[N];
int n, l, r;
bool cmp(line a, line b){
	return a.x == b.x ? a.y > b.y : a.x > b.x;
}
int main(){
	scanf("%d%d%d", &n, &l, &r);
	for(int i = 0 ; i < n ; i++){
		int k, b;
		scanf("%d%d", &k, &b);
		a[i].x = (ll)k * l + b;
		a[i].y = (ll)k * r + b;
	}
	sort(a, a + n, cmp);
	int mn = a[0].y; 
	for(int i = 1 ; i < n ; i++)
		if(a[i].y > mn){
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}
