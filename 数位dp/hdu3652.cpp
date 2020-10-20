#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)

const int SZ = 20;

int dl,d[SZ],dp[SZ][2][2][13];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int dfs(int idx,int is1,int has13,int rem,bool isup){
    if(idx == -1) return has13 && rem == 0;
    if(!isup && ~dp[idx][is1][has13][rem]) return dp[idx][is1][has13][rem];
    int up = isup ? d[idx] : 9;
    int ans = 0;
    rep(i,0,up){
        ans += dfs(idx - 1,i == 1,has13 || (is1 && i == 3),(rem * 10 + i) % 13,isup && i == up);
    }
    if(!isup) dp[idx][is1][has13][rem] = ans;
    return ans;
}

int solve(int x){
    dl = 0;
    for(;x;x /= 10) d[dl++] = x % 10;
    return dfs(dl - 1,0,0,0,true);
}

int main(int argc, char** argv) {
    memset(dp,-1,sizeof dp);
    int b;
    while(~scanf("%d",&b)){
        printf("%d\n",solve(b));
    }
    return 0;
}