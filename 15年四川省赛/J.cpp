#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)

const int N = 1010;
int x[N],y[N];
int n;

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int getidx(int x0,int y0,int d){
    int ii=-1;
    for(int i=0;i<n;++i){
        if(d==0){
            if(x[i]>x0 && y[i]==y0){
                if(ii==-1||x[i]<x[ii])ii=i;
            }
        }
        if(d==1){
            if(x[i]==x0 && y[i]<y0){
                if(ii==-1||y[i]>y[ii])ii=i;
            }
        }
        if(d==2){
            if(x[i]<x0 && y[i]==y0){
                if(ii==-1||x[i]>x[ii])ii=i;
            }
        }
        if(d==3){
            if(x[i]==x0 && y[i]>y0){
                if(ii==-1||y[i]<y[ii])ii=i;
            }
        }
    }
    return ii;
}

int main(int argc, char** argv) {
    while(~scanf("%d",&n)){
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
        }
        int x0=0,y0=0,d=0,ans=0;
        for(;ans<=4*n;++ans){
            int idx = getidx(x0,y0,d);
            if(idx == -1) break;
            else{
                if(d==0){x0=x[idx]-1;y0=y[idx];}
                if(d==1){x0=x[idx];y0=y[idx]+1;}
                if(d==2){x0=x[idx]+1;y0=y[idx];}
                if(d==3){x0=x[idx];y0=y[idx]-1;}
                d = (d + 1) % 4;
            }
        }
        if(ans > 4*n) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}
