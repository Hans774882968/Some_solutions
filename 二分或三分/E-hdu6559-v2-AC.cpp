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
const double EP = 1e-8;

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
        double a = vx*vx + vy*vy - (R*R/H/H)*vz*vz;
        double b = 2*vx*X0 + 2*vy*Y0 + (R*R/H/H)*2*vz*(H-Z0);
        double c = X0*X0 + Y0*Y0 - (R*R/H/H)*(H-Z0)*(H-Z0);
        double xx = max(0.0,b*b - 4*a*c);double de = sqrt(xx);
        double t1 = (-b + de) / (2 * a),t2 = (-b - de) / (2 * a);
        double ans = 3e6;
        if(fabs(val(t1)) < EP) ans = min(ans,t1);
        if(fabs(val(t2)) < EP) ans = min(ans,t2);
        printf("Case %d: %.10lf\n",++cas,ans);
    }
    return 0;
}