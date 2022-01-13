#include <iostream>
#include <vector>
#include <cstring>

#define mod 23333
#define base 261
#define N 1510
using namespace std;
string t;
char s[N];
vector <string> v[mod + 2];
int ans = 0;
void Ins(){
	int len = strlen(s);
	int hash = 0;
	for(int i = 0 ; i < len ; i++){
		hash = (1ll * hash * base) % mod + s[i];
	}
	string t = s;
	for(int i = 0 ; i < v[hash].size() ; i++){
		if(v[hash][i] == t) return;
	}
	v[hash].push_back(t);
	ans++;
}
int n;
int main(){
	cin >> n;
	while(n--){
		cin >> s;
		Ins();
	}
	cout << ans << endl;
	return 0;
}
