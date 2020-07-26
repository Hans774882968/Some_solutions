## Part1

来证明Lucas定理（p质数）：
$$
C(n,m) = C(n \, mod \, p,m \, mod \, p) * C(n / p,m / p)
$$
先证个引理：C(p,x)是p的倍数，当且仅当此组合数不为1。

$$
C_p^x = \frac{p*(p-1)!}{x*(x-1)!*(p-x)!} = p * inv(x) * C_{p-1}^{x-1}
$$
x <= p故逆元存在，上式总成立。

然后正式证明。设：
$$
n = q_n*p+r_n,m=q_m*p+r_m
$$


$$
(1 + x)^n = (1+x)^{p*q_n}*(1+x)^{r_n}\equiv(1+x^p)^{q_n}*(1+x)^{r_n}
$$

两侧二项式定理展开，因为r_n小于p，我们把r_n + 1到p - 1都补上系数0，可以发现乘积两两组合都是不同的幂，所以对于C(n,m)来说右侧只对应一种组合：
$$
C_n^m \equiv C_{q_n}^{q_m}*C_{r_n}^{r_m} = C_{n\,mod\,p}^{m\,mod\,p}*C_{n/p}^{m/p}
$$
这里顺便得到一个推论就是r_n < r_m时C(n,m)是p的倍数。

## Part2

<https://www.luogu.com.cn/problem/P4345>

p = 2333是质数。

**先来点题外话。**上指标求和、下指标求和，这些看上去应该很简单的问题都是紫题了QAQ。同一个问题，如果n = 1e5而p = 1e9 + 7，那么要用莫队而非Lucas。~~组合数学好难~~

我看到此题的第一个办法是先按i % p的数值分类。
$$
\sum_{i=0}^{k}C_{n}^{i}=\sum_{i=0}^{k}C_{n\,mod\,p}^{i\,mod\,p}*C_{n/p}^{i/p}=\sum_{i=0}^{min(p-1,k)}(C_{n\,mod\,p}^{i}*\sum_{j=0}^{(k-i)/p}C_{n/p}^{j})
$$
右边那串可以看成原问题的子问题。又(k - i) / p只有2种可能值，所以我们发现左边的乘子可以写成两个区间和（读者自己写8，我懒得打了）。

然而愚笨的我一开始没想到那俩区间和可以预处理，所以打了一发70分的qwq，它的复杂度
$$
O(p+T*p*log_pn),T=1e5,p=2333,n=1e18
$$
大概是时限的10倍。预处理以后就可以A了。复杂度下降到
$$
O(p^2+T*log_pn)
$$



后来看题解才知道也可以直接按i / p的数值分类。
$$
\sum_{i=0}^{k}C_{n\,mod\,p}^{i\,mod\,p}*C_{n/p}^{i/p}=((\sum_{i=0}^{k/p-1}C_{n/p}^{i})*(\sum_{i=0}^{p-1}C_{n\,mod\,p}^{i}))+(C_{n/p}^{k/p}*\sum_{i=0}^{k\,mod\,p}C_{n\,mod\,p}^{i})
$$

$$
\sum_{i=0}^{k/p-1}C_{n/p}^{i}
$$

是子问题，
$$
\sum_{i=0}^{p-1}C_{n\,mod\,p}^{i},\sum_{i=0}^{k\,mod\,p}C_{n\,mod\,p}^{i}
$$
查预处理的表。

那落单的组合数需要用Lucas定理，这样复杂度会比“法1”多一个log，于是我们希望递归函数多返回一个Lucas的结果来去掉那个log。

所以我写了非递归的代码。~~结果跑的比非递归的还慢QAQ。~~里面
$$
dp[0] = C_{n/p}^{k/p}，dp[1] = \sum_{i=0}^{k/p}C_{n/p}^{i}
$$

fl用来判定子问题的k是否大于0（为了处理递归边界还WA了几发呢）。状态转移方程模仿递归形式即可写出。

法1代码：

```c++
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int SZ = 2338;
const int MOD = 2333;

int Cdown[SZ][SZ],fac[SZ],ifac[SZ];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

template<typename T>T q_pow(T a,T b,T MOD){
    T ret = 1;
    for(;b;b >>= 1){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}

inline int C(int n,int m){
    if(n < m) return 0;
    return (fac[n] * ifac[m] % MOD) * ifac[n - m] % MOD;
}

void init(int lim){
    fac[0] = ifac[0] = 1;for(int i = 1;i <= lim;++i) fac[i] = fac[i - 1] * i % MOD;
    ifac[lim] = q_pow(fac[lim],MOD - 2,MOD);
    for(int i = lim - 1;i >= 1;--i) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    for(int i = 0;i <= lim;++i){
        Cdown[i][0] = 1;
        for(int j = 1;j <= i;++j)
            Cdown[i][j] = (Cdown[i][j - 1] + C(i,j)) % MOD;
        for(int j = i + 1;j <= lim;++j) Cdown[i][j] = Cdown[i][j - 1];
    }
}

int solve(LL n,LL k){
    if(k < 0) return 0;
    if(n < MOD && k < MOD) return Cdown[n][k];
    int sum1 = solve(n / MOD,k / MOD),sum2 = solve(n / MOD,k / MOD - 1);
    int sum3 = solve(n % MOD,k % MOD),sum4 = solve(n % MOD,min(1LL * MOD - 1,k));
    return (sum1 * sum3 % MOD + sum2 * (sum4 - sum3 + MOD) % MOD) % MOD;
}

int main(int argc, char** argv) {
    init(SZ - 6);
    int T;read(T);
    while(T--){
        LL n,k;read(n);read(k);
        printf("%d\n",solve(n,k));
    }
    return 0;
}
```

法2代码：

```c++
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int SZ = 2338;
const int MOD = 2333;

int Cdown[SZ][SZ],C[SZ][SZ];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

void init(int lim){
    for(int i = 0;i <= lim;++i){
        C[i][0] = 1;
        for(int j = 1;j <= i;++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
    for(int i = 0;i <= lim;++i){
        Cdown[i][0] = 1;
        for(int j = 1;j <= i;++j)
            Cdown[i][j] = (Cdown[i][j - 1] + C[i][j]) % MOD;
        for(int j = i + 1;j <= lim;++j) Cdown[i][j] = Cdown[i][j - 1];
    }
}

int main(int argc, char** argv) {
    init(SZ - 6);
    int T;read(T);
    while(T--){
        LL n,k;read(n);read(k);
        vector<int> dn,dk;
        if(k > n) k = n;
        for(LL n0 = n,k0 = k;n0;n0 /= MOD,k0 /= MOD){
            dn.push_back(n0 % MOD);dk.push_back(k0 % MOD);
        }
        int dp[2] = {1,0};
        for(int i = dn.size() - 1,fl = 0;i >= 0;--i){
            dp[1] = (Cdown[dn[i]][MOD - 1] * fl * (dp[1] - dp[0] + MOD) % MOD + Cdown[dn[i]][dk[i]] * dp[0] % MOD) % MOD;
            dp[0] = C[dn[i]][dk[i]] * dp[0] % MOD;
            if(dk[i]) fl = 1;
        }
        printf("%d\n",dp[1]);
    }
    return 0;
}
```

