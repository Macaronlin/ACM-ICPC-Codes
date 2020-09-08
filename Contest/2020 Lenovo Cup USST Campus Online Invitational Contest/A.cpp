#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 5000 + 7;
const int maxm = 1e6 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const long long mod = 998244353;
const double pi = acos(-1.0);

int T;
long long n, m, x, y;
long long ans;

bool check(long long mid) {
    return x * mid <= n + (m - 1) * y;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
        if (x <= y) {
            if (x > n) {
                printf("%d\n", m - 1);
                continue;
            }
        }
        long long l = 1, r = m;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (check(mid)) {
                l = mid + 1;
                ans = max(ans, mid);
            } else {
                r = mid - 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}