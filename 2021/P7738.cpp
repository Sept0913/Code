#include <cstdio>

#define ull unsigned long long
#define N 400000
#define T 65536
using namespace std;
inline int rd(){
	char c;
	bool flag = 0;
	while((c = getchar()) < '0' || c > '9')
	    if(c == '-') flag = 1;
	int res = c - '0';
	while((c = getchar()) >= '0' && c <= '9')
	    res = (res << 3) + (res << 1) + c - '0';
	return flag ? -res : res;
}
bool r[300], s[N + 1][300];
inline int Pre(char c){
	if(c >= '0' && c <= '9') return c - '0';
	else return 10 + c - 'A';
}
inline int Tr_sol(int op, int x){
	if(!op) return x;
	return 15 - x;
}
inline int Tr_num(bool r[], int l){
	int ans = 0;
	int base = 1;
	for(int i = l + 15 ; i >= l ; i--){
		ans += base * r[i];
		base *= 2;
	}
	return ans;
}
ull myRand(ull &k1, ull &k2){
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= (k3 << 23);
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
void gen(int n, ull a1, ull a2){
    for(int i = 1 ; i <= n ; i++)
        for(int j = 0 ; j < 256 ; j++)
            s[i][j] = (myRand(a1, a2) & (1ull << 32)) ? 1 : 0;
}
char c[300];
ull a1, a2;
int n, m, k, ans = 0, in;
int len[20][T];
int h[20][T][20];
int tr[16], y[64];
inline void Sol(){
	scanf("%s", c);
	for(int i = 0 ; i < 64 ; i++)
		y[i] = Tr_sol(ans, Pre(c[i]));
	for(int i = 0 ; i < 64 ; i += 4){
		tr[i / 4] = y[i + 3];
		tr[i / 4] += y[i] * 4096 + y[i + 1] * 256 + y[i + 2] * 16; 
	}
	k = rd();
	for(int i = 0 ; i < 16 ; i++){
		int x = tr[i];
		int nu = i;
		int siz = len[nu][x];
		if(siz == 0) continue;
		for(int j = 0 ; j < siz ; j++){
			in = h[nu][x][j];
			int cnt = 0;
			for(int o = 0 ; o < 256 ; o += 16){
			    int y = Tr_num(s[in], o);
			    int z = tr[o / 16];
				cnt += __builtin_popcount(z ^ y);
				if(cnt > k) break;
			}
			if(cnt <= k){
			    ans = 1;
				puts("1");
				return;
			}
		}
	}
	ans = 0;
	puts("0");
}
int main(){
	freopen("qi.in", "r", stdin);
	freopen("qi.out", "w", stdout);
	n = rd(), m = rd();
	scanf("%llu%llu", &a1, &a2);
	gen(n, a1, a2);
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < 16 ; j++){
			int x = Tr_num(s[i], j * 16);
			h[j][x][len[j][x]++] = i;
		}
	}
	while(m--)
		Sol();
	return 0;
}
