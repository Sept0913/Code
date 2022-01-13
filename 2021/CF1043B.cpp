#include <cstdio>
#include <vector>

#define N 100010
using namespace std;
int a[N], n;
vector <int> ans;
bool check(int k){
	for(int i = 1 ; i <= k ; i++){
		int p = i + k;
		while(p <= n){
			if(a[i] - a[i - 1] != a[p] - a[p - 1])
		        return 0;
			p += k;
		}
	}
	return 1;
}
int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++)
	    scanf("%d", &a[i]);
	for(int i = 1 ; i <= n ; i++)
		if(check(i)) ans.push_back(i);
	int len = ans.size();
	printf("%d\n", len);
	for(int i = 0 ; i < len ; i++)
	    printf("%d ", ans[i]);
	return 0;
}
