#include <bits/stdc++.h>
using namespace std;
int a[1001]={0};
int main(){
	int n,s=0;
	cin>>n;
	for(int x=1;x<=n/2;x++){
		for(int y=1;y<=x/2;y++){
			a[x]+=a[y];
		}
		a[x]++;
		s+=a[x];
	}
	cout<<s+1;
	return 0;
}
