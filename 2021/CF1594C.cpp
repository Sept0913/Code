#include <cstdio>

#define N 300010
using namespace std;
int n, f;
char c, s[N];
void Solve(){
	scanf("%d %c", &n, &c);
	scanf("%s", s + 1);
	f = 1;
	for(int i = 1 ; i <= n ; i++)
		if(s[i] != c) f = 0;
	if(f){
		puts("0");
		return;
	}
	for(int i = 2 ; i <= n ; i++){
		f = 1;
		for(int j = i ; j <= n ; j += i)
			if(s[j] != c) f = 0;
		if(f){
			printf("1\n%d\n", i);
			return;
		}
	}
	printf("2\n%d %d\n", n, n - 1);
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--)
		Solve();
	return 0;
}
