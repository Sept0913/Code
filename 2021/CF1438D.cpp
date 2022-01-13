#include <cstdio>

#define N 100010
using namespace std;
int n, a[N], sum = 0;
int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &a[i]);
		sum ^= a[i];
	}
	if(n % 2 == 0){
		if(sum){
			puts("NO");
			return 0;
		}
		n = n - 1;
	}
	puts("YES");
	printf("%d\n", n - 2);
	for(int i = 1 ; i <= n - 2 ; i += 2)
	    printf("%d %d %d\n", i, i + 1, i + 2);
	for(int i = 1 ; i <= n - 4 ; i += 2)
	    printf("%d %d %d\n", i, i + 1, n);
	return 0;
}
