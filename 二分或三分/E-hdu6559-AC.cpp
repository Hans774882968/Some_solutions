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
#define dwn(i,a,b) for(int i = (a);i >= (b);--i)

const int SZ = 1005;

double R,H,X0,Y0,Z0,vx,vy,vz;

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

double f(double x,double y,double z){
    double rr = (H-z)/H*R;
    return sqrt(x*x + y*y) - rr;
}

double val(double t){
    return f(X0+vx*t,Y0+vy*t,Z0+vz*t);
}

int main(int argc, char** argv) {
    int T,cas = 0;read(T);
    while(T--){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&R,&H,&X0,&Y0,&Z0,&vx,&vy,&vz);
        double l = 0,r = 3e6;
        while(r - l >= 1e-9){
            double t1 = l+(r-l)/3,t2 = r-(r-l)/3;
            if(val(t1) < val(t2)) r = t2;
            else l = t1;
        }
        r = l;l = 0;
        while(r - l >= 1e-9){
            double t = (l+r)/2;double vt = val(t);
            if(vt > 0) l = t;
            else r = t;
        }
        printf("Case %d: %.10lf\n",++cas,l);
    }
    return 0;
}