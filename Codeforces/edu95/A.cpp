#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        long long x, y, k;  cin >> x >> y >> k;
        long double tmp = (y * k + k - 1);
        tmp /= x - 1;
        long long ans = ceil(tmp) + k;
        printf("%lld\n", ans);
        // printf("%lld %lld\n", (ans - k) * (x - 1) + 1, k * (y + 1));
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}