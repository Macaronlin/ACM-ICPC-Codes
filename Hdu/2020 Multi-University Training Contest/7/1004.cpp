#include <bits/stdc++.h>

using namespace std; 

long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }

long long calc(long long a, long long b, long long c, long long n) {
    long long res;
    if (a == 0) {
        return (n + 1) * (b / c);
    }
    else if (a >= c || b >= c) {
        long long t = calc(a % c, b % c, c, n);
        long long t1 = 1LL * n * (n + 1) / 2;
        return t1 * (a / c) + (n + 1) * (b / c) + t;
    }
    else {
        long long m = (a * n + b) / c, nm = n * m;
        long long t = calc(c, c - b - 1, a, m - 1);
        return nm - t;
    }
    return res;
}

long long qpow(long long a, long long k, int p) {
    long long res = 1;
    while (k) {
        if (k & 1)  res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}
const int N = 1000000 + 10;
long long _pow[N];
int main() {
    // (a * x + b) % m % 2 == 1
    int t = 3, a = 2, c = 3, m = 5;
    int aa = 0;
    for (int i = 0; i <= t; i++) {
        for (int j = 0; j <= t; j++) {
            int pos = abs(i - j), x = i + j;
            for (int k = 0; k < pos; k++)   x = (a * x + c) % m;
            cout << i << ' ' << j << ' ' << x << '\n';
        }
    }
    cout << aa << '\n';
    int T;  scanf("%d", &T);
    while (T--) {
        int t, a, c, m; scanf("%d %d %d %d", &t, &a, &c, &m);
        _pow[0] = 1;
        for (int i = 1; i <= m; i++)    _pow[i] = _pow[i - 1] * a % m;
        long long ans1 = 0, ans2 = 1LL * (t + 1) * (t + 1);
        if (a == 0) {
            if (c & 1)  ans1 = ans2 - (t + 1);
        }
        else if (a == 1) {
            for (int k = 1; k <= t; k++) {
                bool flag = ((c+1)&1) & (k&1);
                ans1 += flag * (t - k + 1);
            }
            ans1 *= 2;
        }
        else {
            long long sum = 0;
            // v1 != v2
            for (int k = 1; k <= t; k++) {
                sum = (sum + c * _pow[k - 1]) % m;
                long long _a = 2 * _pow[k] % m, _b = (k * _pow[k] + sum) % m;
                long long t1 = (_b & 1) * (t - k + 1); // ((_a & 1) ^ (_b ^ 1)) * (t - k + 1);
                long long t2 = calc(_a, _b, m, t - k);
                long long t3 = calc(_a, _b, m * 2, t - k);
                // cout << k << ' ' << abs(t1 - (t2 - t3)) << ' ' << t1 << ' ' << t2 << ' ' << t3 << '\n';
                ans1 += abs(t1 - (t2 - t3));
            }
            ans1 *= 2;
            // v1 == v2 : 0
        }
        ans1 = ans2 - ans1;
        long long g = gcd(ans1, ans2);
        printf("%lld/%lld\n", ans1 / g, ans2 / g);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}