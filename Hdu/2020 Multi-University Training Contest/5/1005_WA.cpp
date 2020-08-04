#include <bits/stdc++.h>

using namespace std; 

const int P = 998244353;
const int N = 6000000 + 10;

long long inv[N], invfac[N], fac[N], dp[N];

long long qpow(long long a, long long k = P - 2) {
    long long res = 1;
    while (k) {
        if (k & 1)  res = res * a % P;
        a = a * a % P;
        k >>= 1;
    }
    return res;
}

long long Choose(int n, int m) { return n >= m && m >= 0 ? fac[n] * invfac[m] % P * invfac[n - m] % P : 0; }
long long sqr(long long x) { return x * x % P; }

int main() {
    fac[0] = inv[0] = inv[1] = invfac[0] = 1;
    for (int i = 1; i < N; i++)    fac[i] = fac[i - 1] * i % P;
    for (int i = 2; i < N; i++)    inv[i] = (P - P / i) * inv[P % i] % P;
    for (int i = 1; i < N; i++)    invfac[i] = invfac[i - 1] * inv[i] % P;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % P;
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = (dp[i] + 
                Choose(i - 1, j) * Choose(i, j + 1) % P * sqr(j) % P * qpow(i, i - 1 - j) % P
            ) % P;
        }
        cout << i << ' ' << dp[i] << '\n';
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

// n = 1, (k = 1) (   0 /    1 =          0) (k = 2) (   0 /    1 =          0)
// n = 2, (k = 1) (   3 /    4 =  249561089) (k = 2) (   5 /    4 =  748683266)
// n = 3, (k = 1) (  43 /   27 =  702468250) (k = 2) (  67 /   27 =  258804094)
// n = 4, (k = 1) ( 634 /  256 =  522518531) (k = 2) ( 958 /  256 =  257359876)