#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;
char s[110];
int check(char c){
	if(c == 'K' || c == 'A' || c == 'C' || c == 'E') return 1;
	if(c >= 'p' && c <= 't') return 2;
	if(c == 'N') return 3;
}
vector <char> one, two, no;
int main(){
	//freopen("UVa11103.in", "r", stdin);
	//freopen("UVa11103.out", "w", stdout);
	while(scanf("%s", s)){
		if(s[0] == '0') return 0;
		one.clear(); two.clear(); no.clear();
		int len = strlen(s);
		for(int i = 0 ; i < len ; i++){
			char c = s[i];
			int ck = check(c);
			if(ck == 1) two.push_back(c);
			if(ck == 2) one.push_back(c);
			if(ck == 3) no.push_back(c);
		}
		char t[310];
		int l = 150, r = 151;
		while(one.size() > 0){
			t[r++] = one.back();
			one.pop_back();
			if(r - l > 2){
				t[l--] = two.back();
				two.pop_back();
			}
			if(two.size() == 0) break;
		}
		if(r - l > 1){
			while(no.size() > 0){
				t[l--] = 'N';
				no.pop_back();
			}
		}
		else if(r - l == 1 && one.size() > 0){
			t[r++] = one.back();
			one.pop_back();
			while(no.size() > 0){
				t[l--] = 'N';
				no.pop_back();
			}
		}
		if(r - l <= 1) puts("no WFF possible");
		else{
			for(int j = l + 1 ; j < r ; j++) printf("%c", t[j]);
			puts("");
		}
	}
	return 0;
}
