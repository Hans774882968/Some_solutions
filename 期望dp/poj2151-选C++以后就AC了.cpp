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

const int SZ = 33;

int m,t,n;
double dp[1005][SZ][SZ],p[1005][SZ];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    while(~scanf("%d%d%d",&m,&t,&n) && (m || t || n)){
        rep(i,1,t)
            rep(j,1,m)
                scanf("%lf",&p[i][j]);
        rep(i,1,t){
            dp[i][1][0] = 1 - p[i][1];
            rep(j,2,m) dp[i][j][0] = dp[i][j - 1][0] * (1 - p[i][j]);
            dp[i][1][1] = p[i][1];
            rep(j,2,m){
                rep(k,1,j){
                    dp[i][j][k] = p[i][j] * dp[i][j - 1][k - 1] + (1 - p[i][j]) * dp[i][j - 1][k];
                }
            }
        }
        double p1 = 1,p2 = 1;
        rep(i,1,t){
            double tmp = 0;
            re_(j,1,n) tmp += dp[i][m][j];
            p1 *= 1 - dp[i][m][0];
            p2 *= tmp;
        }
        printf("%.3lf\n",p1 - p2);
    }
    return 0;
}