#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)

const int SZ = 20;

int dl,d[SZ];LL dp[SZ][2][2];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

LL dfs(int idx,int is4,int has49,bool isup){
    if(idx == -1) return has49;
    if(!isup && ~dp[idx][is4][has49]) return dp[idx][is4][has49];
    int up = isup ? d[idx] : 9;
    LL ans = 0;
    rep(i,0,up){
        ans += dfs(idx - 1,i == 4,has49 || (is4 && i == 9),isup && i == up);
    }
    if(!isup) dp[idx][is4][has49] = ans;
    return ans;
}

LL solve(LL x){
    dl = 0;
    for(;x;x /= 10) d[dl++] = x % 10;
    return dfs(dl - 1,0,0,true);
}

int main(int argc, char** argv) {
    memset(dp,-1,sizeof dp);
    LL b;int T;read(T);
    while(T--){
        read(b);
        printf("%lld\n",solve(b));
    }
    return 0;
}