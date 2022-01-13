#include <cstdio>
#include <algorithm>
#include <vector>

#define N 200010
using namespace std;
int n;
int a[N], cnt[N];
int c[N];
vector <int> num;
int main(){
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for(int i = 1 ; i <= n ; i++)
		if(cnt[i] == 0) num.push_back(i);
	int len = num.size(), now = 0;
	printf("%d\n", len);
	for(int i = 0 ; i < n ; i++){
		if(cnt[a[i]] > 1 && num[now] < a[i]){
			cnt[a[i]]--;
			a[i] = num[now];
			now++;
			c[a[i]] = 1;
		}
		else if(c[a[i]]){
			a[i] = num[now];
			now++;
			c[a[i]] = 1;
		}
		else
			c[a[i]] = 1;
	}
	for(int i = 0 ; i < n ; i++)
	    printf("%d ", a[i]);
	return 0;
}
