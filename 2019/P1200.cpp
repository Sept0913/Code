#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int j1=1,j2=1,t1,t2;
    for(int i1=0;i1<s1.size();i1++){
    	j1*=int(s1[i1]-'@');
	}
	for(int i2=0;i2<s2.size();i2++){
    	j2*=int(s2[i2]-'@');
	}
	t1=j1%47;
	t2=j2%47;
	if(t1==t2) cout<<"GO";else cout<<"STAY";
	return 0;
}
