#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l,END##i=r;i<=END##i;++i)
#define dn(r,l,i) for(int i=r,END##i=l;i>=END##i;--i)
using namespace std;
typedef long long i64;
typedef unsigned int       u32;
typedef unsigned long long u64;
const int INF =2147483647;
const int MAXN=(1<<18)+3;
int k,m,W[MAXN],V[MAXN],I[MAXN],J[MAXN],t,n;
int qread(){
    int w=1,c,ret;
    while((c=getchar())> '9'||c< '0') w=(c=='-'?-1:1); ret=c-'0';
    while((c=getchar())>='0'&&c<='9') ret=ret*10+c-'0';
    return ret*w;
}
bool F[MAXN],G[MAXN];
int main(){
    dn(qread(),1,TT){
        bool f=true;
        k=qread(),m=qread(),n=1<<k; up(0,n-1,i) W[i]=qread(),I[i]=i,F[i]=true;
        up(1,k,i){
		    up(0,(1<<k-i)-1,j){
                int l=(j<<i),r=l+(1<<i),w=l+r>>1,t1=l,t2=w,t=l;
                while(t1<w&&t2<r){
                    if(W[t1]<W[t2]) V[t]=W[t1],J[t++]=I[t1++];
                    else            V[t]=W[t2],J[t++]=I[t2++];
                }
                while(t1<w) V[t]=W[t1],J[t++]=I[t1++];
                while(t2<r) V[t]=W[t2],J[t++]=I[t2++];
                int p=w,q=l; bool f=false;
                up(l,w-1,o) 
				    if(F[I[o]]) {
                        while(p<r&&W[p]<=W[o]+m) 
						    f|=F[I[p++]]; 
						G[I[o]]=f;
                    } 
				    else G[I[o]]=0;
            f=false;
            up(w,r-1,o) 
			    if(F[I[o]]) {
                    while(q<w&&W[q]<=W[o]+m) 
					    f|=F[I[q++]]; 
					G[I[o]]=f;
                }
			    else G[I[o]]=0;
            up(l,r-1,o) 
			    W[o]=V[o],I[o]=J[o],F[I[o]]=G[I[o]];
	        } 
    	}
        puts(F[0]?"Kotori":"Yoshino");
    }
    return 0;
}
