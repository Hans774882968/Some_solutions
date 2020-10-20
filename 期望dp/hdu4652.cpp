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

const int SZ = 100000 + 5;

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

LL q_pow(LL a,LL b){
    LL ret = 1;
    for(;b;b >>= 1){
        if(b & 1) ret *= a;
        a *= a;
    }
    return ret;
}

int main(int argc, char** argv) {
    int T;
    while(cin >> T){
        while(T--){
            int opt,n,m;cin >> opt >> m >> n;//read(opt);read(m);read(n);
            if(opt == 0) printf("%.9lf\n",1.0 * (q_pow(m,n) - 1) / (m - 1));
            else{
                double ans = 1,tmp = 1;
                for(int i = 1;i < n;i++){
                    tmp *= 1.0 * m / (m - i);
                    ans += tmp;
                }
                printf("%.9lf\n",ans);
            }
        }
    }
    return 0;
}
