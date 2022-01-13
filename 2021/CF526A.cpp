#include <cstdio>

using namespace std;
int n;
char s[110];
int main(){
	scanf("%d%s", &n, s);
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '*'){
			int res = n - i - 1;
			for(int j = 1 ; j <= n / 4 ; j++){
				int t = i;
				bool f = 1;
				for(int k = 0 ; k < 4 ; k++){
					t += j;
					if(s[t] != '*') f = 0;
				}
				if(f){
					puts("yes");
					return 0;
				}
			}
		}
	}
	puts("no");
	return 0;
}
