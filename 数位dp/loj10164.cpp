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

const int SZ = 15;

int dl,d[SZ],dp[SZ][11];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int dfs(int idx,int las,bool isup){
    if(idx == -1) return 1;
    if(!isup && ~dp[idx][las]) return dp[idx][las];
    int up = isup ? d[idx] : 9;
    int ans = 0;
    rep(i,las,up){
        ans += dfs(idx - 1,i,isup && i == up);
    }
    if(!isup) dp[idx][las] = ans;
    return ans;
}

int solve(int x){
    dl = 0;
    for(;x;x /= 10) d[dl++] = x % 10;
    return dfs(dl - 1,0,true);
}

int main(int argc, char** argv) {
    memset(dp,-1,sizeof dp);
    int a,b;
    while(~scanf("%d%d",&a,&b)){
        printf("%d\n",solve(b) - solve(a - 1));
    }
    return 0;
}