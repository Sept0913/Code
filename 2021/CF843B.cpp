#include <ctime>
#include <iostream>
#include <algorithm>

#define N 50010
using namespace std;
inline unsigned int rnd(){
	static unsigned int seed = rand();
	seed ^= seed << 17, seed ^= seed >> 5, seed ^= seed << 23;
	return seed;
}
int v[N], nxt[N], n, x, beg;
int main(){
	srand(time(0));
	cin >> n >> beg >> x;
	int ind = beg;
	for(int i = 1 ; i <= 1000 ; i++){
		int r = rnd() % n + 1;
		cout << "? " << r << endl;
		cin >> v[r] >> nxt[r];
		if(v[r] <= x && v[r] > v[ind]) ind = r;
		if(v[r] == x){
			cout << "! " << x << endl;
			return 0;
		}
	}
	for(int i = ind ; i != -1 ; i = nxt[i]){
		cout << "? " << i << endl;
		cin >> v[i] >> nxt[i];
		if(v[i] >= x){
			cout << "! " << v[i] << endl;
			return 0;
		}
	}
	cout << "! -1" << endl;
	return 0;
}
