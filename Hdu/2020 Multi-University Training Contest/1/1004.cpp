#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
long long qpow(long long a, long long k = P - 2) {
    long long res = 1;
    while (k) {
        if (k & 1)  res = res * a % P;
        k >>= 1;
        a = a * a % P;
    }
    return res;
}

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n;  scanf("%d", &n);
        long long ans = qpow(26, n);
        printf("%lld\n", ans);
    }
    // system("pause");
    return 0;
}