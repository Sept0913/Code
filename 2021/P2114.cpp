#include <bits/stdc++.h>

#define N 100010
using namespace std;
pair <char, int> op[N];
int n, m, t;
char s[20];
int calc(int bit, int x){
	for(int i = 0 ; i < n ; i++){
		int k = (op[i].second >> bit) & 1;
		char p = op[i].first;
		if(p == 'A') x &= k;
		else if(p == 'O') x |= k;
		else x ^= k;
	}
	return x;
}
int val = 0, ans = 0;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i++){
		scanf("%s%d", s, &t);
		op[i] = make_pair(s[0], t);
	}
	for(int i = 30 ; i >= 0 ; i--){
		int a = calc(i, 0), b = calc(i, 1);
		if(b > a && val + (1 << i) <= m)
		    val += (1 << i), ans += (b << i);
		else
		    ans += (a << i);
	}
	printf("%d\n", ans);
	return 0;
}
