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

const int N = 1e5+10;
int n,m,k;

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    while(~scanf("%d%d%d", &n,&m,&k)){
        unsigned long long ans = 0;
        rep(i,1,min(n,k / 2 - 1)){
            int j = min(m,k / 2 - i);
            ans += (n - i + 1) * (1LL * (2LL * m + 1 - j) * j / 2);
        }
        cout << ans << endl;
    }
    return 0;
}
