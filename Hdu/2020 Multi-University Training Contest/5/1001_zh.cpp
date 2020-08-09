#include <bits/stdc++.h>
//#include <bits/extc++.h>

using namespace std;
//using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 1e7 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const long long mod = 998244353;
const double pi = acos(-1.0);

long long poww(long long a, long long b) {
    long long base = a, res = 1;
    while (b) {
        if (b & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        b >>= 1;
    }
    return res % mod;
}

long long sum[maxm];

void init() {
    for (int i = 1; i <= 8e6; i++) {
        long long tmp = (i * i) % mod;
        long long inv = poww(tmp, mod - 2);
        sum[i] = (sum[i - 1] + inv) % mod;
    }
}

int T;
int n;

int main() {
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    freopen("1001_1.out", "w", stdout);
#endif
    init();
    scanf("%d", &T);
    while (T--) {
        // scanf("%d", &n);
        n = T;
        long long ans = (sum[n] * poww(n, mod - 2)) % mod;
        ans = (ans * 3) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}