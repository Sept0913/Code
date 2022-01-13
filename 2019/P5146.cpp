#include <bits/stdc++.h>
using namespace std;
long long a[1000000],maxx=0,minn=0,cha;
int maxt(long long a,long long b){
	if(a>b) return a;
	return b;
}
int mint(long long a,long long b){
	if(a<b) return a;
	return b;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	maxx=minn=a[0];
	for(int q=1;q<n;q++){
		maxx=maxt(a[q],maxx);
		minn=mint(a[q],minn);
	}
	cha=maxx-minn;
	cout<<cha;
	return 0;
}
