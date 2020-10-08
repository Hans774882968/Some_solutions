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

const int N = 5e6 + 5,mod[2] = {int(1e6 + 3),int(1e6 + 7)};
char x[N],y[N],ans[N];
int l1,l2,al;
int p29[2][N],hsh[2][N],h_x[2];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

bool jdg(int l,int r){
    re_(i,0,2){
        if((hsh[i][r] - 1LL * p29[i][r - l + 1] * hsh[i][l - 1] % mod[i] + mod[i]) % mod[i] != h_x[i])
            return false;
    }
    return true;
}

int main(int argc, char** argv) {
    p29[0][0] = p29[1][0] = 1;
    re_(i,0,2) rep(j,1,N - 5) p29[i][j] = p29[i][j - 1] * 29 % mod[i];
    while(~scanf("%s",x)){
        scanf("%s",y);
        l1 = strlen(x);l2 = strlen(y);
        hsh[0][al = 0] = hsh[1][0] = h_x[0] = h_x[1] = 0;
        re_(i,0,2) re_(j,0,l1) h_x[i] = 29 * h_x[i] % mod[i] + x[j] - 'a';
        re_(i,0,l2){
            ans[++al] = y[i];
            re_(j,0,2) hsh[j][al] = 29 * hsh[j][al - 1] % mod[j] + y[i] - 'a';
            if(al < l1) continue;
            if(jdg(al - l1 + 1,al)) al -= l1;
        }
        ans[++al] = '\0';
        puts(ans + 1);
    }
    return 0;
}