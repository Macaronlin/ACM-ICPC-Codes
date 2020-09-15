#include <bits/stdc++.h>

using namespace std; 

const int N = 300000 + 10;
#define int long long
int n, m;
long long b[N], w[N];
long long sum[N][2];
long long dp[N];
struct Node {
    int l, r, t;
    long long c;
    bool operator < (const Node &tmp) const { return r < tmp.r; }
}node[N];

struct Tree {
    long long maxv[N << 2], lazy[N << 2];
    void Push_down(int o) {
        if (lazy[o]) {
            lazy[o << 1] += lazy[o];
            lazy[o << 1 | 1] += lazy[o];
            maxv[o << 1] += lazy[o];
            maxv[o << 1 | 1] += lazy[o];
            lazy[o] = 0;
        }
    }
    void Update(int o, int L, int R, int l, int r, long long val) {
        if (l > r)  return;
        if (l <= L && R <= r) {
            maxv[o] += val;
            lazy[o] += val;
        }
        else {
            Push_down(o);
            int M = (L + R) >> 1;
            if (l <= M) Update(o << 1, L, M, l, r, val);
            if (r >= M + 1) Update(o << 1 | 1, M + 1, R, l, r, val);
            maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
        }
    }
    long long Query(int o, int L, int R, int l, int r) {
        if (l > r)  return 0;
        if (l <= L && R <= r)   return maxv[o];
        else {
            int M = (L + R) >> 1;
            long long res = LLONG_MIN;
            if (l <= M) res = max(res, Query(o << 1, L, M, l, r));
            if (r >= M + 1) res = max(res, Query(o << 1 | 1, M + 1, R, l, r));
            return res;
        }
    }
}tr[2];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	freopen("tst.out", "w", stdout);
#endif
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", b + i);
        sum[i][0] = sum[i - 1][0] + b[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", w + i);
        sum[i][1] = sum[i - 1][1] + w[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld %lld %lld %lld", &node[i].t, &node[i].l, &node[i].r, &node[i].c);
        node[i].t--;
    }
    sort(node + 1, node + 1 + m);
    int p = 1;
    for (int i = 1; i <= n; i++) {
        tr[0].Update(1, 1, n, i, i, dp[i - 1] - sum[i - 1][0]);
        tr[1].Update(1, 1, n, i, i, dp[i - 1] - sum[i - 1][1]);

        while (p <= m && node[p].r == i) {
            int t = node[p].t, l = node[p].l;
            tr[t].Update(1, 1, n, 1, l, node[p].c);
            p++;
        }
        
        printf("i = %lld, ", i);
        for (int j = 1; j <= i; j++) {
            printf("(%lld, %lld), ", tr[0].Query(1, 1, n, j, j), tr[1].Query(1, 1, n, j, j));
        };

        dp[i] = max(
            tr[0].Query(1, 1, n, 1, i) + sum[i][0],
            tr[1].Query(1, 1, n, 1, i) + sum[i][1]
        );

        
        cout << dp[i] << '\n';
    }
    printf("%lld\n", dp[n]);
    return 0;
}