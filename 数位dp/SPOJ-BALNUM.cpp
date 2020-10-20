#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)
#define dwn(i,a,b) for(int i = (a);i >= (b);--i)

const int SZ = 21;

int p3[SZ];
int dl,d[SZ];ULL dp[SZ][59055];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

bool jdg(int S){
    for(int i = 0;S;S /= 3,i ^= 1) if(S % 3 && (S % 3) % 2 == i) return false;
    return true;
}

ULL dfs(int idx,int S,bool first1,bool isup){
    if(idx == -1) return jdg(S);
    if(!isup && first1 && ~dp[idx][S]) return dp[idx][S];
    int up = isup ? d[idx] : 9;
    ULL ans = 0;
    rep(i,0,up){
        int S0 = (S / p3[i]) % 3 <= 1 ? S + p3[i] : S - p3[i];
        if(!i){
            ans += dfs(idx - 1,first1 ? S0 : S,first1,isup && i == up);
        }
        else ans += dfs(idx - 1,S0,true,isup && i == up);
    }
    if(!isup && first1) dp[idx][S] = ans;
    return ans;
}

ULL solve(ULL x){
    dl = 0;
    for(;x;x /= 10) d[dl++] = x % 10;
    return dfs(dl - 1,0,false,true);
}

int main(int argc, char** argv) {
    p3[0] = 1;rep(i,1,10) p3[i] = p3[i - 1] * 3;
    memset(dp,-1,sizeof dp);
    int T;read(T);
    while(T--){
        ULL a,b;read(a);read(b);
        cout << solve(b) - solve(a - 1) << endl;
    }
    return 0;
}