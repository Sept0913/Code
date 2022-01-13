#include <bits/stdc++.h>
using namespace std;
char mima(char z,int n){
	int lw;
	if(z+n<='z') return z+n;
	return (z+n)-26;
}
int main(){
    string a;
	int n;
	cin>>n;
	cin>>a;
	for(int i=0;i<a.size();i++){
		cout<<mima(a[i],n);
	}
	return 0;
}
