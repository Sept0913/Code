#include <bits/stdc++.h>

using namespace std;
int n, a[110], mn = 110, mx, i1, i2;
void Sol(){
	mn = 110, mx = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		if(mn > a[i]) mn = a[i], i1 = i + 1;
		if(mx < a[i]) mx = a[i], i2 = i + 1;
	}
	if(i1 > i2) swap(i1, i2);
	cout << min(min(i2, n - i1 + 1), i1 + n - i2 + 1) << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--) Sol();
	return 0;
}
