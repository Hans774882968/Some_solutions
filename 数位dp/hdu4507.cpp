#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)

const int SZ = 20,mod = 1e9 + 7;

LL p10[SZ];
int dl,d[SZ];

struct Ret{
    LL s2,s1,cont;
    Ret(LL s2 = -1,LL s1 = 0,LL cont = 0):s2(s2),s1(s1),cont(cont){}
}dp[SZ][7][7];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

Ret dfs(int idx,int bs,int rem,LL val,bool isup){
    if(idx == -1){
        if(bs && rem) return Ret(0,0,1);
        return Ret(0,0,0);
    }
    if(!isup && ~dp[idx][bs][rem].s2) return dp[idx][bs][rem];
    int up = isup ? d[idx] : 9;
    Ret ans(0);
    rep(i,0,up){
        if(i == 7) continue;
        Ret tmp = dfs(idx - 1,(bs + i) % 7,(rem * 10 + i) % 7,(val * 10 + i) % mod,isup && i == up);
        LL A = p10[idx] * i % mod;
        ans.cont = (ans.cont + tmp.cont) % mod;
        ans.s1 = (ans.s1 + A * tmp.cont % mod + tmp.s1) % mod;
        ans.s2 = (ans.s2 + (tmp.cont * A % mod) * A % mod + 2 * tmp.s1 * A % mod + tmp.s2) % mod;
    }
    if(!isup) dp[idx][bs][rem] = ans;
    return ans;
}

LL solve(LL x){
    if(!x) return 0;
    dl = 0;
    for(;x;x /= 10) d[dl++] = x % 10;
    return dfs(dl - 1,0,0,0,true).s2;
}

int main(int argc, char** argv) {
    memset(dp,-1,sizeof dp);
    p10[0] = 1;rep(i,1,18) p10[i] = p10[i - 1] * 10 % mod;
    int T;read(T);
    while(T--){
        LL a,b;read(a);read(b);
        printf("%lld\n",(solve(b) - solve(a - 1) + mod) % mod);
    }
    return 0;
}