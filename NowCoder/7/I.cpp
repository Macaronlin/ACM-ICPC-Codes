#include <bits/stdc++.h>

using namespace std; 

const int N = 5001;
// const int P = 1000000000 + 7;
int P;

int add(int a, int b) { a += b; return a < P ? a : a - P; }
int sub(int a, int b) { a -= b; return a < 0 ? a + P : a; }
int mul(int a, int b) { return 1LL * a * b % P; }

int qpow(int a, int k = P - 2) {
    int res = 1;
    while (k) {
        if (k & 1)  res = mul(res, a);
        a = mul(a, a);
        k >>= 1;
    }
    return res;
}

int f1[N], f2[N], g1[N], g2[N];

int fac[N], inv[N], invfac[N];

int Choose(int n, int m) { return n >= m && m >= 0 ? mul(mul(fac[n], invfac[m]), invfac[n - m]) : 0; }

int main() {
    int T;  scanf("%d", &T);
    scanf("%d", &P);
    // P = 1000000000 + 7;
    fac[0] = inv[0] = inv[1] = invfac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
    for (int i = 2; i < N; i++) inv[i] = mul((P - P / i), inv[P % i]);
    for (int i = 1; i < N; i++) invfac[i] = mul(invfac[i - 1], inv[i]);
    f1[0] = f1[1] = 1;
    for (int i = 2; i < N; i++) f1[i] = qpow(i, i - 2);
    f2[0] = f2[1] = 1;
    for (int i = 2; i < N; i++) {
        for (int j = 0; j < i; j++) {
            f2[i] = add(f2[i], mul(mul(Choose(i - 1, j), f1[j + 1]), f2[i - j - 1]));
        }
    }
    g1[0] = g1[1] = 0;
    for (int i = 2; i < N; i++) {
        for (int j = 1; j < i; j++) {
            g1[i] = add(g1[i], mul(mul(mul(j, j), Choose(i - 2, j - 1)), qpow(i - 1, i - j - 1)));
        }
        g1[i] = mul(g1[i], i);
    }
    g2[0] = g2[1] = 0;
    for (int i = 2; i < N; i++) {
        for (int j = 0; j < i; j++) {
            g2[i] = add(g2[i], mul(Choose(i - 1, j), add(mul(g1[j + 1], f2[i - j - 1]), mul(g2[i - j - 1], f1[j + 1]))));
        }
    }
    while (T--) {
        int n;  scanf("%d", &n);
        printf("%d\n", g2[n]);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}