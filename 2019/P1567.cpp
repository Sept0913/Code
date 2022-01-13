#include <bits/stdc++.h>
using namespace std;
long long big(long long a,long long b){
	if(a>b) return a;
	return b;
}
long long a[1000000];
int main(){
	long long n,lx=0,maxt=0;
	cin>>n;
	for(long long i=0;i<n;i++) cin>>a[i];
	for(long long i=1;i<n;i++){
		if(a[i]>a[i-1]) lx++;
		else{
			maxt=big(lx,maxt);
			lx=0;
		}
	}
	cout<<maxt+1;
	return 0;
}
