#include <iostream>
using namespace std;
int main(){
	int n,s=0,x,d;
	cin>>n>>d;
	for(int a=1;a<=n;a++){
		x=a;
		while(x>0){
			if(x%10==d) s++;
			x=x/10;
		}
	}
	cout<<s;
	return 0;
}
