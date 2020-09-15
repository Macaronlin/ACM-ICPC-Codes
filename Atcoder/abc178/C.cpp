#include <bits/stdc++.h>

using namespace std;

const int P = 1000000000 + 7;

long long qpow(long long a, long long k) {
    long long res = 1;
    while (k) {
        if (k & 1)  res = res * a % P;
        a = a * a % P;
        k >>= 1;
    }
    return res;
}

int main() {
    int n;  cin >> n;
    if (n < 2)  cout << 0 << '\n';
    else {
        long long ans = qpow(10, n) - qpow(9, n) * 2 + qpow(8, n);
        ans = (ans % P + P) % P;
        cout << ans << '\n';
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}