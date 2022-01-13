#include <bits/stdc++.h>

#define N 2000010
#define ll long long
using namespace std;
ll n, m, cnt;
ll siz[N], tr[N][2], tr_m[N][4];
bool vis[N];
ll finds(ll u);
void dfs(ll x, ll u);
bool finda(ll x);
ll newn(ll &x);
void Sol(){
    for(int i = 0 ; i <= cnt ; i++){
        siz[i] = 0, vis[i] = 0;
        tr_m[i][0] = tr_m[i][1] = tr_m[i][2] = tr_m[i][3] = 0;
    }
    cnt = 1;
    bool f = 0;
    scanf("%lld", &m);
    while(m--){
        scanf("%lld", &n);
        f = (n == 1);
        for(ll i = 1 ; i <= n ; i++)
            scanf("%lld%lld", &tr[i][0], &tr[i][1]);
        if(!finds(1)) continue;
        dfs(1, 1);
    }
    puts((f || !finda(1)) ? "Almost Complete" : "No");
}
int main(){
    int t; scanf("%d", &t);
    while(t--) Sol();
    return 0;
}
ll finds(ll u){
    if(tr[u][0] && !finds(tr[u][0])) return 0;
    if(tr[u][1] && !finds(tr[u][1])) return 0;
    ll s1 = siz[tr[u][0]], s2 = siz[tr[u][1]];
    siz[u] = s1 + s2 + 1;
    if(min(s1, s2) > 1) return 0;
    return 1;
}
void dfs(ll x, ll u){
    ll s1 = siz[tr[u][0]], s2 = siz[tr[u][1]];
    if(!s1 && !s2){
        vis[x] = 1;
        return;
    }
    if(s1 == 1 && s2 == 1){
        vis[newn(tr_m[x][2])] = 1;
        vis[newn(tr_m[x][3])] = 1;
        return;
    }
    if(s1 >= 1 && s2 == 1) dfs(newn(tr_m[x][2]), tr[u][0]);
    if(s1 >= 1 && s2 == 0) dfs(newn(tr_m[x][0]), tr[u][0]);
    if(s2 >= 1 && s1 == 1) dfs(newn(tr_m[x][3]), tr[u][1]);
    if(s2 >= 1 && s1 == 0) dfs(newn(tr_m[x][1]), tr[u][1]);
}
bool finda(ll x){
    if(vis[x]) return 0;
    if(!tr_m[x][0] || !tr_m[x][1] || !tr_m[x][2] || !tr_m[x][3])
        return 1;
    if(finda(tr_m[x][0]) || finda(tr_m[x][1]) || finda(tr_m[x][2]) || finda(tr_m[x][3]))
        return 1;
    return 0;
}
ll newn(ll &x){
    x = !x ? (++cnt) : x;
    return x;
}
