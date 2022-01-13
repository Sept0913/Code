#include <cstdio>
#include <cstring>

#define N 1000010
using namespace std;
int fail[N];
char s[N], p[N];
int a, b;
int main(){
	scanf("%d%s", &b, p + 1);
	int j = 0;
	for(int i = 2 ; i <= b ; i++){
		while(p[i] != p[j + 1] && j > 0) j = fail[j];
		if(p[i] == p[j + 1]) j++, fail[i] = j;
	}
	printf("%d\n", b - fail[b]);
	return 0;
}
