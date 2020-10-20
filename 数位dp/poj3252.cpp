#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>
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

int dl,d[SZ],dp[SZ][SZ << 1];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

inline int ID(int v){return v + SZ;}

int dfs(int idx,int v,bool first1,bool isup){
    if(idx == -1) return v >= 0;
    if(!isup && first1 && ~dp[idx][ID(v)]) return dp[idx][ID(v)];
    int up = isup ? d[idx] : 1;
    int ans = 0;
    rep(i,0,up){
        if(i == 0){
            ans += dfs(idx - 1,v + first1,first1,isup && i == up);
        }
        else ans += dfs(idx - 1,v - 1,true,isup && i == up);
    }
    if(!isup && first1) dp[idx][ID(v)] = ans;
    return ans;
}

int solve(int x){
    dl = 0;
    for(;x;x >>= 1) d[dl++] = x & 1;
    return dfs(dl - 1,0,false,true);
}

int main(int argc, char** argv) {
    memset(dp,-1,sizeof dp);
    int a,b;read(a);read(b);
    printf("%d\n",solve(b) - solve(a - 1));
    return 0;
}