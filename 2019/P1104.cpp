#include <bits/stdc++.h>
using namespace std;
int x[100000000];
int main(){
	int y[100],m[100],d[1000],e[100],n;
	cin>>n;
	char s[100][20];
	for(int i=0;i<n;i++){
		scanf("%s,%d,%d,%d",s[i],y[i],m[i],d[i]);
		e[i]=y[i]*10000+m[i]*100+d[i];
	}
	for(int z=0;z<n;z++){
		x[e[z]]++;
	}
	for(int y=0;y<n;y++){
		if (x[e[y]]>0) cout<<s[y]<<endl;
	}
	return 0;
}
