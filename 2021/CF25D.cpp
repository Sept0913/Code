#include <cstdio>
#include <vector>

#define N 1010
using namespace std;
int f[N];
int n, u, v;
vector <int> a, b, c;
void init(){
	for(int i = 1 ; i < N ; i++) f[i] = i;
}
int find(int a){
    if(f[a] == a) return a;
    return f[a] = find(f[a]);
}
void merge(int a, int b){
    int t1 = find(a), t2 = find(b);
    if(t1 != t2) f[t1] = t2;
}
bool check(int a, int b){
	return find(a) == find(b);
}
int main(){
	init();
	scanf("%d", &n);
	for(int i = 1 ; i < n ; i++){
		scanf("%d%d", &u, &v);
		if(check(u, v)) a.push_back(u), b.push_back(v);
		merge(u, v);
	}
	for(int i = 1 ; i <= n ; i++)
		if(f[i] == i) c.push_back(i);
	printf("%d\n", a.size());
	int cnt = 0;
	for(int i = 0 ; i < a.size() ; i++){
		printf("%d %d %d %d\n", a[i], b[i], c[i], c[i + 1]);
		merge(c[i], c[i + 1]);
	}
	return 0;
}
