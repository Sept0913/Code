#include <cstdio>
#include <cstring>

#define N 1000010
using namespace std;
int fail[N];
char s[N], p[N];
int a, b;
int main(){
	scanf("%s%s", s + 1, p + 1);
	a = strlen(s + 1), b = strlen(p + 1);
	int j = 0;
	for(int i = 2 ; i <= b ; i++){
		while(p[i] != p[j + 1] && j > 0) j = fail[j];
		if(p[i] == p[j + 1]) j++, fail[i] = j;
	}
	j = 0;
	for(int i = 1 ; i <= a ; i++){
		while(s[i] != p[j + 1] && j > 0) j = fail[j];
		if(s[i] == p[j + 1]) j++;
		if(j == b){
			printf("%d\n", i - b + 1);
			j = fail[j];
		}
	}
	for(int i = 1 ; i <= b ; i++) printf("%d ", fail[i]);
	return 0;
}
