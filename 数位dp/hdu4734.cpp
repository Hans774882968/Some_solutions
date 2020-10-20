#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)

const int SZ = 13;

int dl,d[SZ],dp[SZ][4610],FA;

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int dfs(int idx,int v,bool isup){
    if(idx == -1) return 1;
    if(!isup && ~dp[idx][v]) return dp[idx][v];
    int up = isup ? d[idx] : 9;
    int ans = 0;
    rep(i,0,up){
        int nv = v - (1 << idx) * i;
        if(nv < 0) continue;
        ans += dfs(idx - 1,nv,isup && i == up);
    }
    if(!isup) dp[idx][v] = ans;
    return ans;
}

int solve(int x){
    dl = 0;
    for(;x;x /= 10) d[dl++] = x % 10;
    return dfs(dl - 1,FA,true);
}

int main(int argc, char** argv) {
    memset(dp,-1,sizeof dp);
    int a,b;int T,cas = 0;read(T);
    while(T--){
        read(a);read(b);
        FA = 0;
        for(int i = 0;a;a /= 10,i++) FA += (a % 10) * (1 << i);
        printf("Case #%d: %d\n",++cas,solve(b));
    }
    return 0;
}