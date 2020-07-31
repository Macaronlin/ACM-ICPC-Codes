#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 10;
long long a[N];

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n;  scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            long long x;  scanf("%lld", &x);
            int cnt = (100 - 1) / x;
            long long y;  scanf("%lld", &y);
            a[i] = cnt * y;
        }
        sort(a + 1, a + 1 + n);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[1]) {
                cnt++;
            }
        }
        double ans = 1.0 - cnt / 2.0 / n;
        printf("%.16lf\n", ans);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}