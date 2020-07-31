#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
struct Node {
    int w;
    long long v;
    bool operator < (const Node &tmp) const {return w < tmp.w; }
}a[N], b[N];
int sum[N];
long long dp_a[N * N], dp_b[N * N];

int Solve(int n, Node *a, long long *dp) {
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= 1000000; i++)  dp[i] = -1e18;
    int sum = 0;
    for (int i = 1; i <= n; i++, sum += a[i].w) {
        for (int j = sum; j >= 0; j--) {
            dp[j + a[i].w] = max(dp[j + a[i].w], dp[j] + a[i].v);
        }
    }
    return sum;
}

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n, m;   scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)    scanf("%d %lld", &a[i].w, &a[i].v);
        int sum1 = Solve(n, a, dp_a);
        for (int i = 1; i <= m; i++)    scanf("%d %lld", &b[i].w, &b[i].v);
        int sum2 = Solve(m, b, dp_b);
        long long ans = 0;
        for (int i = min(sum1, sum2); i; i--) {
            ans = max(ans, dp_a[i] + dp_b[i]);
        }
        printf("%lld\n", ans);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}