#include <cstdio>
#include <algorithm>

using namespace std;
int n, a[60];
void Sol(){
	int ans = 1;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++) scanf("%d", &a[i]);
	if(n == 1){
		puts("0");
		return;
	}
	sort(a, a + n);
	int mi = a[0], ma = a[n - 1];
	for(int s = mi + 1 ; s <= ma * 2 ; s++){
		int k = 0, I1 = 0, I2 = n - 1;
		while(I1 < I2){
			if(a[I1] + a[I2] == s) I1++, I2--, k++;
			if(a[I1] + a[I2] < s) I1++;
			if(a[I1] + a[I2] > s) I2--;
		}
		ans = max(ans, k);
	}
	printf("%d\n", ans);
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--)
	    Sol();
	return 0;
}
