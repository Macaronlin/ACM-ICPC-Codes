#include <bits/stdc++.h>

using namespace std; 

const int P = 998244353;
const int N = 6000000 + 10;
long long fac[N];

long long qpow(long long a, long long k = P - 2) {
    long long res = 1;
    while (k) {
        if (k & 1)  res = res * a % P;
        a = a * a % P;
        k >>= 1;
    }
    return res;
}

long long sqr(long long x) { return x * x % P;}
long long sum[N];
int main() {
    // freopen("1001.out", "w", stdout);
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % P;
    for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + sqr(qpow(i));
    int T;  scanf("%d", &T);
    while (T--) {
        int n;  scanf("%d", &n);
        // int n = T;
        long long ans = 3LL* sum[n] % P * qpow(n) % P;
        printf("%lld\n", ans);
    }    
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}