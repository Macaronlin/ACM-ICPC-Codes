#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 10;

long long a[N];

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n;  scanf("%d", &n);
        for (int i = 1; i <= n; i++)    scanf("%lld", a + i);
        sort(a + 1, a + 1 + n);
        long long ans = LLONG_MIN;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                ans = max(ans, 0LL);
            }
        }
        ans = max(ans, a[1] * a[2] * a[3] * a[4] * a[5]);
        ans = max(ans, a[1] * a[2] * a[3] * a[4] * a[n]);
        ans = max(ans, a[1] * a[2] * a[3] * a[n - 1] * a[n]);
        ans = max(ans, a[1] * a[2] * a[n - 2] * a[n - 1] * a[n]);
        ans = max(ans, a[1] * a[n - 3] * a[n - 2] * a[n - 1] * a[n]);
        ans = max(ans, a[n - 4] * a[n - 3] * a[n - 2] * a[n - 1] * a[n]);
        printf("%lld\n", ans);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}