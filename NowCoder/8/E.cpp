#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 10;
long long add[N * 3], sub[N * 3], sum[N * 3];
int main() {
    for (int len = 3; len < N; len++) {
        for (int a1 = 1; a1 * len + 3 < N; a1++) {
            int a2 = a1 + 1, a3 = a1 + 2;
            int l1 = a1 * len + 3, r1 = a3 * len - 3;
            add[l1]++;  add[r1 + 2]--;
            int l2 = a2 * len + 1, r2 = r1 + 1;
            sub[l2]++;  sub[r2 + 1]--;
        }
    }
    for (int i = 2; i < N; i++) add[i] += add[i - 2];
    for (int i = 1; i < N; i++) sub[i] += sub[i - 1];
    for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + add[i] - sub[i];
    // for (int i = 1; i < N; i++) cout << i << ' ' << ' ' << sum[i] << endl;
    for (int i = 1; i < N; i++) sum[i] += sum[i - 1];
    // for (int i = 1; i < 20; i++) {
    //     cout << sum[i] << ' ' << i << endl;
    // }
    int T;  scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int l, r;   scanf("%d %d", &l, &r);
        printf("Case #%d: ", t);
        printf("%lld\n", sum[r] - sum[l - 1]);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}