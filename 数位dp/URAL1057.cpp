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

const int SZ = 35;

int k,B;
int dl,d[SZ],dp[SZ][SZ];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int dfs(int idx,int v,bool isup){
    if(idx == -1) return v == k;
    if(!isup && ~dp[idx][v]) return dp[idx][v];
    int up = isup ? d[idx] : B - 1;
    int ans = 0;
    rep(i,0,up){
        if(i > 1) break;
        ans += dfs(idx - 1,v + (i == 1),isup && i == up);
    }
    if(!isup) dp[idx][v] = ans;
    return ans;
}

int solve(int x){
    dl = 0;
    for(;x;x /= B) d[dl++] = x % B;
    return dfs(dl - 1,0,true);
}

int main(int argc, char** argv) {
    memset(dp,-1,sizeof dp);
    int a,b;
    while(~scanf("%d%d%d%d",&a,&b,&k,&B)){
        printf("%d\n",solve(b) - solve(a - 1));
    }
    return 0;
}