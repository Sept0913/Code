#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define N 100010
#define ll long long
using namespace std;
struct node{
	ll c, p;
	int ind;
};
priority_queue <ll> q;
node a[N];
int n, k;
bool cmp(node a, node b){
	return a.p < b.p;
}
ll ans[N];
vector <ll> v;
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0 ; i < n ; i++)
	    a[i].ind = i;
	for(int i = 0 ; i < n ; i++)
	    scanf("%lld", &a[i].p);
	for(int i = 0 ; i < n ; i++)
	    scanf("%lld", &a[i].c);
	sort(a, a + n, cmp);
	for(int i = 0 ; i < n ; i++){
		int in = a[i].ind;
		ans[in] = a[i].c;
		v.clear();
		while(v.size() < k && !q.empty()){
			ans[in] += q.top();
			v.push_back(q.top());
			q.pop();
		}
		int len = v.size();
		for(int j = 0 ; j < len ; j++)
		    q.push(v[j]);
		q.push(a[i].c);
	}
	for(int i = 0 ; i < n ; i++)
	    printf("%lld ", ans[i]);
	return 0;
}
