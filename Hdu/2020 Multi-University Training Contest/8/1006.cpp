#include <bits/stdc++.h>

using namespace std; 

// struct N
#define int long long
pair<int, int> Merge(pair<int, int> a, pair<int, int> b) {
    if (a > b)  swap(a, b);
    if (a.first == LONG_LONG_MIN && b.first == LONG_LONG_MIN) return {LONG_LONG_MIN, LONG_LONG_MIN};
    if (a.second < b.first) return {LONG_LONG_MIN, LONG_LONG_MIN};
    return {max(a.first, b.first), min(a.second, b.second)};
}
pair<int, int> calc(pair<int, int> a, int k) {
    return {a.first - k, a.second + k};
}
const int N = 1000000 + 10;
pair <int, int> a[N], b[N];
signed main() {
    int T;  scanf("%lld", &T);
    while (T--) {
        int n, k;   scanf("%lld %lld", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &a[i].first, &a[i].second);
        }
        b[n] = a[n];
        for (int i = n - 1; i >= 1; i--) {
            b[i] = Merge(calc(b[i + 1], k), a[i]);
        }
        if (b[1].first == LONG_LONG_MIN) {
            puts("NO");
        }
        else {
            puts("YES");
            int now = b[1].first;
            vector <int> ans;   ans.push_back(now);
            for (int i = 2; i <= n; i++) {
                now = max(now - k, b[i].first);
                ans.push_back(now);
            }
            for (int i = 0; i < (int)ans.size(); i++) {
                printf("%lld%c", ans[i], " \n"[i == n - 1]);
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     printf("(%lld, %lld)\n", b[i].first, b[i].second);
        // }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}