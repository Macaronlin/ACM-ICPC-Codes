#include <bits/stdc++.h>

using namespace std;

const int P = 1000000009;
const int inv2 = 500000005;
const int x = 383008016;    // x*x = 5
const int invx = 276601605;
const int A = 691504013;
const int B = 308495997;

long long qpow(long long a, long long k = P - 2) {
    long long res = 1;
    while (k) {
        if (k & 1) res = res * a % P;
        k >>= 1;
        a = a * a % P;
    }
    return res;
}

const int N = 200000 + 10;
long long fac[N], inv[N], invfac[N];

long long Choose(int n, int m) { return n >= m && m >= 0 ? fac[n] * invfac[m] % P * invfac[n - m] % P : 0; }

long long pow_Ac[N], pow_Bc[N];

int main() {
    fac[0] = inv[0] = inv[1] = invfac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % P;
    for (int i = 2; i < N; i++) inv[i] = (P - P / i) * inv[P % i] % P;
    for (int i = 1; i < N; i++) invfac[i] = invfac[i - 1] * inv[i] % P;
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n, c, k;
        scanf("%lld %lld %lld", &n, &c, &k);
        long long ans = 0;
        long long Ac = qpow(A, c);
        long long Bc = qpow(B, c);
        pow_Ac[0] = 1;
        pow_Bc[0] = 1;
        for (int i = 1; i <= k; i++) {
            pow_Ac[i] = (pow_Ac[i - 1] * Ac) % P;
            pow_Bc[i] = (pow_Bc[i - 1] * Bc) % P;
        }
        for (int r = 0; r <= k; r++) {
            long long tans = (!(r & 1)) * 2 - 1;
            tans = tans * Choose(k, r) % P;
            //long long t = qpow(qpow(A, c), k - r) * qpow(qpow(B, c), r) % P;
            long long t = pow_Ac[k - r] * pow_Bc[r] % P;
            if (t == 1) tans = tans * (n + 1) % P;
            else tans = tans * (qpow(t, n + 1) - 1) % P * qpow(t - 1) % P;
            ans = (ans + tans) % P;
        }
        ans = ans * qpow(invx, k) % P;
        ans = (ans + P) % P;
        printf("%lld\n", ans);
    }
    system("pause");
    return 0;
}