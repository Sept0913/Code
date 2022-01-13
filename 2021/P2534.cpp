#include <bits/stdc++.h>

using namespace std;
int n, a[60], b[60];
inline int check(){
	int tmp = 0;
	for(int i = 1 ; i <= n ; i++)
	    tmp += abs(a[i + 1] - a[i]) != 1;
	return tmp;
}
bool have = 0;
void dfs(int now, int ste, int lon){
	if(have || now + check() > ste) return;
	if(check() == 0){
		have = 1;
		return;
	}
	for(int i = 1 ; i <= n ; i++){
		if(i == lon) continue;
		reverse(a + 1, a + i + 1);
		dfs(now + 1, ste, i);
		reverse(a + 1, a + i + 1);
	}
}
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n + 1);
	for(int i = 1 ; i <= n ; i++)
	    a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
	a[n + 1] = n + 1;
	for(int i = 0 ;  ; i++){
		have = 0;
		dfs(0, i, 0);
		if(have){
			cout << i;
			return 0;
		}
	}
	return 0;
}
