#include <cstdio>
#include <vector>

#define mod 10007
using namespace std;
int n, t, x;
vector <int> v[mod + 2];
bool check(){
	int k = (x % mod + mod) % mod;
	for(int i = 0 ; i < v[k].size() ; i++)
	    if(v[k][i] == x) return 0;
	v[k].push_back(x);
	return 1;
}
void sol(){
	for(int i = 0 ; i < mod ; i++) v[i].clear();
	scanf("%d", &n);
	while(n--){
		scanf("%d", &x);
		if(check()) printf("%d ", x);
	}
	puts("");
}
int main(){
	scanf("%d", &t);
	while(t--) sol();
	return 0;
}
