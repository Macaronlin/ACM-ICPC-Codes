#include <bits/stdc++.h>

using namespace std; 

const int P = 998244353;

long long mul(long long a, long long b) { return 1LL * a * b % P; }
long long add(long long a, long long b) { a %= P; b %= P; return a + b < P ? a + b : a + b - P; }
long long sub(long long a, long long b) { a %= P; b %= P; return a - b < 0 ? a - b + P : a - b; }

long long qpow(long long a, long long k = P - 2) {
    long long res = 1;
    while (k) {
        if (k & 1)  res = mul(res, a);
        a = mul(a, a);
        k >>= 1;
    }
    return res;
}

// const int N = 
// long long fac[N];

signed main() {
    long long T;  scanf("%lld", &T);
    while (T--) {
        long long n;    scanf("%lld", &n);
        long long n2 = qpow(2, n);
        long long n3 = qpow(3, n);
        long long n4 = qpow(4, n);
        long long ans = (2 * n3 + n4 + n2) % P * qpow(n2) % P;
        printf("%lld\n", ans);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}