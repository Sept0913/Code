#include <iostream>
using namespace std;
int main(){
	int f[1000000],y[1000000],a[1000000],s[1000000],i[1000000];
	int n,k,t,zc=0;
	cin>>n>>k;
	for(int x=1;x<=n;x++){
	cin>>a[x];
	zc+=a[x];
	} 
	int min1=a[1];
	for(int w=1;w<=n;w++) if(a[w]<a[w-1]) min1=a[w];
	for(int q=1;q<=n;q++) for(t=1;t<=min1;t++) i[t]+=a[q]%t;
	int min2=i[1];
	for(int l=1;l<=min1;l++) if((zc-i[l])/k>(zc-i[l-1])/k) min2=i[l];
	cout<<min2;
	return 0;
}
