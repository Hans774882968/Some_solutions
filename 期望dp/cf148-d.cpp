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

int w,b;
double dp[SZ][SZ][2];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    read(w);read(b);
    rep(i,1,w) rep(who,0,1) dp[i][0][who] = 1;
    rep(j,1,b) rep(who,0,1) dp[0][j][who] = 0;
    dp[0][0][0] = 0;dp[0][0][1] = 1;
    rep(i,1,w){
        rep(j,1,b){
            rep(who,0,1){
                double wp = 1.0 * i / (i + j),bp = 1.0 * j / (i + j),wp0 = 1.0 * i / (i + j - 1),bp0 = 1.0 * (j - 1) / (i + j - 1);
                dp[i][j][who] = wp;
                if(who == 0){
                    dp[i][j][who] += bp * (1 - dp[i][j - 1][1]);
                }
                else{
                    dp[i][j][who] += bp * (wp0 * (1 - dp[i - 1][j - 1][0]) + bp0 * (1 - (j >= 2 ? dp[i][j - 2][0] : 0)));
                }
            }
        }
    }
    printf("%.9lf\n",dp[w][b][0]);
    return 0;
}