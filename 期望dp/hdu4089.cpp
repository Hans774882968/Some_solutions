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

const int SZ = 2005;
const double EP = 1e-6;

double dp[SZ][SZ],c[SZ],pwp[SZ];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    int n,m,k;double p1,p2,p3,p4;
    while(~scanf("%d%d%d%lf%lf%lf%lf",&n,&m,&k,&p1,&p2,&p3,&p4)){
        if(p4 < EP){
            puts("0.00000");
            continue;
        }
        dp[1][1] = p4 / (1 - p1 - p2);
        double p21 = p2 / (1 - p1),p31 = p3 / (1 - p1),p41 = p4 / (1 - p1);
        pwp[0] = 1;rep(i,1,n) pwp[i] = pwp[i - 1] * p21;
        rep(i,2,n){
            double sum = 0;
            c[1] = p41;
            rep(j,2,i){
                if(j <= k) c[j] = p41 + p31 * dp[i - 1][j - 1];
                else c[j] = p31 * dp[i - 1][j - 1];
            }
            rep(j,1,i) sum += c[j] * pwp[i - j];
            dp[i][i] = sum / (1 - pwp[i]);
            dp[i][1] = p21 * dp[i][i] + p41;
            rep(j,2,i) dp[i][j] = p21 * dp[i][j - 1] + p31 * dp[i - 1][j - 1] + (j <= k ? p41 : 0);
        }
        printf("%.5lf\n",dp[n][m]);
    }
    return 0;
}