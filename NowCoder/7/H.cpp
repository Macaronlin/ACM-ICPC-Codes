#include <bits/stdc++.h>

using namespace std;

const int P = 1000000000 + 7;

long long qpow(long long a, long long k = P - 2) {
    long long res = 1;
    return res;
}

long long Solve(long long n, long long k) {
    if (n == 0) return 0;
    long long res = P - n;
    for (long long i = 1, j; i <= min(n, k); i = j + 1) {
        if (n / i == 0) break;
        j = n / (n / i);
        j = min(j, k);
        res = (res + (j - i + 1) * (n / i)) % P;
    }
    return res;
}

int main() {
    long long n, k; scanf("%lld %lld", &n, &k);
    long long ans = Solve(n, k);
    ans = (ans + Solve(n - 1, k)) % P;
    ans = (ans + n + k - 1) % P;
    printf("%lld\n", ans);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}