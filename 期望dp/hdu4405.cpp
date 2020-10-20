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

const int SZ = 100000 + 5;

int n,m;
int moves[SZ];
double dp[SZ];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    const double po = 1.0 / 6;
    while(~scanf("%d%d",&n,&m) && (n || m)){
        dp[n] = 0;memset(moves,0,sizeof moves);
        for(int i = 1;i <= m;i++){
            int x,y;read(x);read(y);
            moves[x] = y;
        }
        for(int i = n;i >= 1;i--){
            if(moves[i]){
                int tmp = moves[i];
                for(;moves[tmp] != tmp;tmp = moves[tmp]);
                moves[i] = tmp;
            }
            else moves[i] = i;
        }
        for(int i = n - 1;i >= 0;i--){
            if(moves[i] != i){
                dp[i] = dp[moves[i]];
                continue;
            }
            dp[i] = 1;
            for(int j = 1;j <= 6 && i + j <= n;j++){
                dp[i] += po * dp[moves[i + j]];
            }
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}
