#include <bits/stdc++.h>
using namespace std;
char swaps(char zy[1000][1000],int n){
	char yb[1000][1000];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			yb[j][n-i-1]=zy[i][j];
		}
	}
	for(int h=0;h<n;h++){
		for(int s=0;s<n;s++){
			zy[h][s]=yb[h][s];
		}
	}
}
char zy[1000][1000],yb[1000][1000],zf[1000][1000];
int main(){
	int len,si;
	cin>>len;
	for(int o=0;o<len;o++){
		for(int p=0;p<len;p++){
			cin>>zy[o][p];
		}
	}
	for(int u=0;u<len;u++){
		for(int v=0;v<len;v++){
			cin>>zf[u][v];
		}
	}
	for(si=1;si<=4;si++){
		for(int a=0;a<len;a++){
		    for(int b=0;b<len;b++){
			    if(zy[a][b]=='O') cout<<zf[a][b];
		    }
	    }
	    swaps(zy,len);
	}
	return 0;
}
