#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
string s;
int n;
int main(){
	cin >> n;
	if(n % 2 == 0){
		puts("NOT POSSIBLE");
		return 0;
	}
	cin >> s;
	string a = s.substr(0, n / 2), b = s.substr(n / 2 + 1, n / 2);
	bool f = 0, g = 0;
	int i = n / 2, j = 0;
	for( ; i < n && j < n / 2 ; i++)
	    if(a[j] == s[i]) j++;
	if(j == n / 2) f = 1;
	i = 0, j = 0;
	for( ; i < n / 2 + 1 && j < n / 2 ; i++)
	    if(b[j] == s[i]) j++;
	if(j == n / 2) g = 1;
	if(!f && !g){
		puts("NOT POSSIBLE");
		return 0;
	}
	if(f && g && a != b){
		puts("NOT UNIQUE");
		return 0;
	}
	if(f) cout << a;
	else  cout << b;
	return 0;
}
