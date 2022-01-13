#include <cstdio>

#define ll long long
using namespace std;
void add(ll a, ll b){
	printf("%lld + %lld = %lld\n", a, b, a + b);
}
void del(ll a, ll b){
	printf("%lld - %lld = %lld\n", a, b, a - b);
}
void tim(ll a, ll b){
	printf("%lld * %lld = %lld\n", a, b, a * b);
}
int n;
int main(){
	scanf("%d", &n);
	if(n <= 3){
		puts("NO");
		return 0;
	}
	puts("YES");
	if(n % 2 == 0){
		tim(1, 2);
		tim(2, 3);
		tim(6, 4);
		for(int i = 5 ; i <= n ; i += 2){
			del(i + 1, i);
			tim(1, 24);
		}
	}
	else{
		tim(2, 4);
		tim(3, 5);
		add(8, 15);
		add(1, 23);
		for(int i = 6 ; i <= n ; i += 2){
			del(i + 1, i);
			tim(1, 24);
		}
	}
	return 0;
}
