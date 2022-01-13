#include <cstdio>

#define N 100010
using namespace std;
int n, u, v;
int deg[N], One[N], Two[N];
int one = -1, two = -1;
int main(){
	scanf("%d", &n);
	for(int i = 0 ; i < n - 1 ; i++){
		scanf("%d%d", &u, &v);
		deg[u]++;
		deg[v]++;
	}
	for(int i = 1 ; i <= n ; i++){
		if(deg[i] == 1) One[++one] = i;
		else if(deg[i] >= 3) Two[++two] = i;
	}
	if(two >= 1){
		puts("No");
		return 0;
	}
	puts("Yes");
	if(two == -1) printf("1\n%d %d", One[0], One[1]);
	else{
		printf("%d\n", one + 1);
		for(int i = 0 ; i <= one ; i++)
		    printf("%d %d\n", Two[0], One[i]);
	}
	return 0;
}
