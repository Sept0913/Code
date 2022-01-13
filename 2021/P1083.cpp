#include <cstdio>
#include <cstring>

#define N 1000010
#define up(l,r,i) for(int i=l,END##i=r;i<=END##i;i++)

using namespace std;
int ans = 0;
int n, m;
int r[N], d[N], s[N], t[N];
long long ne[N], ch[N];
bool ck(int x){
	memset(ne, 0, sizeof(ne));
	memset(ch, 0, sizeof(ch));
    up(1, x, i){
        ch[s[i]] += d[i];
        ch[t[i] + 1] -= d[i];
    }
    up(1, n, i){
        ne[i] = ne[i - 1] + ch[i];
        if(ne[i] > r[i]) return 1;
    }
    return 0;
}
int main(){
	scanf("%d%d", &n, &m);
    up(1, n, i) scanf("%d", &r[i]);
    up(1, m, i) scanf("%d%d%d", &d[i], &s[i], &t[i]);
    if(!ck(m)){
        puts("0");
        return 0;
    }
    int L = 1, R = m;
    while(L < R){
        int M = (L + R) >> 1;
        if(ck(M)) R = M;
        else L = M + 1;
    }
    printf("-1\n%d\n", R);
	return 0;
}
