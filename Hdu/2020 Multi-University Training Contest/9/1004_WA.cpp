#include <bits/stdc++.h>

using namespace std; 

long long qpow(long long a, long long k, long long p) {
    long long res = 1;
    while (k) {
        if (k & 1)  res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

string cmp(int a, int b) {
    return a > b ? "大于" : a == b ? "等于" : "小于";
}

int prime[] = {2, 3, 5, 7};
int main() {
    int p = 23;
    int kp = sqrt(p + 0.5);
    for (int a = 1; a < p; a++) {
        cout << a << ' ' << qpow(a, p - 2, p) << ' ' << cmp(a, kp) << ' ' << cmp(qpow(a, p - 2, p), kp) << '\n';
    }
    // long long p;    scanf("%lld", &p);
    // int q;  scanf("%d", &q);
    // while (q--) {
    //     long long a;  scanf("%lld", &a);
    // }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}