#include <bits/stdc++.h>

using namespace std; 

int main() {
    // for (int n = 1; n <= 1000000; n++) {
    //     long long x = 1LL * n * (n + 1) * (2 * n + 1) / 6;
    //     long long kx = sqrt(x + 0.5);
    //     if (kx * kx == x) {
    //         printf("%d\n", n);
    //     }
    // }
    int T;  scanf("%d", &T);
    while (T--) {
        long long x;    scanf("%lld", &x);
        if (x == 1 || x == 24) {
            puts("Fake news!");
        }
        else {
            puts("Nobody knows it better than me!");
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}