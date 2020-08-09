#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e6 + 7;
const int maxm = 1e7 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const long long mod = 998244353;
const double pi = acos(-1.0);

int n, m;
int f[maxn];
int w[maxn];
long long pre[maxn];
long long ans;
int cnt[maxn];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + w[f[i]];
    }
    int l = 1, r = 1;
    long long res = 0;
    while (r <= n) {
        ++cnt[f[r]];
        if (cnt[f[r]] == 1) {
            res += w[f[r]];
        } else if (cnt[f[r]] == 2) {
            res -= w[f[r]];
        }
        ans = max(ans, res);
        while (l <= r && cnt[f[r]] > 2) {
            --cnt[f[l]];
            if (cnt[f[l]] == 1) {
                res += w[f[l]];
            } else if (cnt[f[l]] == 0) {
                res -= w[f[l]];
            }
            ++l;
        }
        ans = max(ans, res);
        ++r;
    }
    printf("%lld\n", ans);
    return 0;
}