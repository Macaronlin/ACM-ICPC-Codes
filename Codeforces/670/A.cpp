#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 10;

int a[N];

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n;  scanf("%d", &n);
        for (int i = 1; i <= n; i++)    scanf("%d", a + i);
        unordered_map <int, int> ump;
        for (int i = 1; i <= n; i++)    ump[a[i]]++;
        int ans = 0;
        for (int i = 0; i <= 100; i++) {
            if (ump[i]) {
                ump[i]--;
            }
            else {
                ans += i;
                break;
            }
        }
        for (int i = 0; i <= 100; i++) {
            if (ump[i]) {
                ump[i]--;
            }
            else {
                ans += i;
                break;
            }
        }
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}