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
#include <stack>
#include <algorithm>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)
#define dwn(i,a,b) for(int i = (a);i >= (b);--i)

const int SZ = 20,LCM10 = 2520;

int dl,d[SZ];LL dp[SZ][LCM10 + 5][50];
int mp[LCM10 + 5];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int gcd(int a,int b){return !b ? a : gcd(b,a % b);}
int lcm(int a,int b){return a / gcd(a,b) * b;}

LL dfs(int idx,int v,int lc,bool isup){
    if(idx == -1) return v % lc == 0;
    if(!isup && ~dp[idx][v][mp[lc]]) return dp[idx][v][mp[lc]];
    int up = isup ? d[idx] : 9;
    LL ans = 0;
    rep(i,0,up){
        int nv = (v * 10 + i) % LCM10;
        int nlc = i ? lcm(lc,i) : lc;
        ans += dfs(idx - 1,nv,nlc,isup && i == up);
    }
    if(!isup) dp[idx][v][mp[lc]] = ans;
    return ans;
}

LL solve(LL x){
    dl = 0;
    for(;x;x /= 10) d[dl++] = x % 10;
    return dfs(dl - 1,0,1,true);
}

int main(int argc, char** argv) {
    memset(dp,-1,sizeof dp);
    memset(mp,-1,sizeof mp);
    for(int i = 1,cnt = 0;i <= LCM10;++i) if(LCM10 % i == 0) mp[i] = cnt++;
    int T;read(T);
    while(T--){
        LL a,b;read(a);read(b);
        LL ans = solve(b) - solve(a - 1);
        printf("%I64d\n",ans);
    }
    return 0;
}