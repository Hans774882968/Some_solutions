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

const int SZ = 525;

double a[SZ],b[SZ],p[25];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    int T;read(T);
    while(T--){
        int n,k1,k2,k3,a0,b0,c0;
        read(n);read(k1);read(k2);read(k3);read(a0);read(b0);read(c0);
        int tot = k1 + k2 + k3;
        double p0 = 1.0 / (k1 * k2 * k3);
        rep(i,3,tot) p[i] = 0;
        rep(i,1,tot) a[i + n] = b[i + n] = 0;
        rep(i,1,k1){
            rep(j,1,k2){
                rep(k,1,k3){
                    if(i == a0 && j == b0 && k == c0) continue;
                    p[i + j + k] += p0;
                }
            }
        }
        dwn(i,n,0){
            a[i] = p0;
            rep(j,3,tot) a[i] += p[j] * a[i + j];
            b[i] = 1;
            rep(j,3,tot) b[i] += p[j] * b[i + j];
        }
        printf("%.15lf\n",b[0] / (1 - a[0]));
    }
    return 0;
}