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

const int p10[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
const int N = 1e5+10;
int n,a[N],b[N];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    while(~scanf("%d", &n)){
        LL ans = 0;
        re_(i,0,n) read(a[i]);
        for(int i = 1; i <= 9; i++)
        {
            re_(j,0,n) b[j] = a[j] % p10[i];
            sort(b,b + n);
            re_(j,0,n){
                int pos = lower_bound(b,b + n,p10[i] - b[j]) - b;
                if(pos < j) ans += j - pos;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
