#include <bits/stdc++.h>
using namespace std;
int a[101]={0};
int main(){
	int n,k=0,i,ii;
	bool flag=true;
	cin>>n;
	for(i=n+1;;i++){
		while(ii>0){
			ii=i;
			a[k]=n%10;
		    ii=ii/10;
		    k++;
			}
	    for(int t=0;t<k/2;t++){
		    if(a[t]!=a[k-t-1] ){flag=false;break;}
			}
	    if(flag) {cout<<i;break;}
	    for(int w=0;w<101;w++) a[w]=0;
	    k=0;
	}
	return 0;
}
