#include <bits/stdc++.h>

using namespace std; 

const int P = 998244353;
const int N = 1500000 + 10;

int add(int a, int b) { return a + b < P ? a + b : a + b - P; }
int sub(int a, int b) { return a - b < 0 ? a - b + P : a - b; }
int mul(int a, int b) { return 1LL * a * b % P; }

int inv[N << 2], invfac[N << 2], fac[N << 2];

int qpow(int a, long long k = P - 2) {
    int res = 1;
    while (k) {
        if (k & 1)  res = mul(res, a);
        a = mul(a, a);
        k >>= 1;
    }
    return res;
}

template <class T>
struct _FFT {
    int n, nn;  T w[2][N << 2], rev[N << 2], tmp;
    int init_len(int _n) { for (n = 1; n <= _n; n <<= 1); return n; }
    int Init(int _n) {
        init_len(_n);
        if (n == nn) { return n; }  nn = n;
        T w0 = qpow(3, (P - 1) / n);    w[0][0] = w[1][0] = 1;
        for (int i = 1; i < n; i++) w[0][i] = w[1][n - i] = mul(w[0][i - 1], w0);
        for (int i = 0; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
        return n;
    }
    void FFT(T *a, int opt) {
        for (int i = 0; i < n; i++) { if (i < rev[i]) swap(a[i], a[rev[i]]); }
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0, t = n / (i << 1); j < n; j += i << 1) {
                for (int k = j, l = 0; k < j + i; k++, l += t) {
                    T x = a[k], y = mul(w[opt][l], a[k + i]);
                    a[k] = add(x, y);
                    a[k + i] = sub(x, y);
                }
            }
        }
        if (opt) { tmp = inv[n]; for (int i = 0; i < n; i++) { a[i] = mul(a[i], tmp); } }
    }
};

template <class T>
struct Poly {
    _FFT<T> FFT;
    T X[N << 2], Y[N << 2], A[N << 2], B[N << 2], C[N << 2];
    T AA[N << 2], BB[N << 2], AL[N << 2], BL[N << 2];
    void Fill(T *a, T *b, int n, int len) {
        if (a != b) memcpy(a, b, sizeof(T) * n);
        fill(a + n, a + len, 0);
    }
    void Dot_Mul(T *a, T *b, int len, T *c) {
        for (int i = 0; i < len; i++) {
            c[i] = mul(a[i], b[i]);
        }
    }
    void Mul(T *a, int n, T *b, int m, T *c) {
        int len = FFT.Init(n + m - 1);
        Fill(X, a, n, len), Fill(Y, b, m, len);
        FFT.FFT(X, 0), FFT.FFT(Y, 0);
        Dot_Mul(X, Y, len, c);
        FFT.FFT(c, 1);
    }
    void Int(T *a, int n, T *b) {
        for (int i = n - 1; i >= 0; i--) {
            b[i + 1] = mul(a[i], inv[i + 1]);
        }
        b[0] = 0;
    }
    void Der(T *a, int n, T *b) {
        for (int i = 1; i < n; i++) {
            b[i - 1] = mul(a[i], i);
        }
        b[n - 1] = 0;
    }
    void Inv(T *a, int n, T *b) {
        if (n == 1) { b[0] = qpow(a[0]), b[1] = 0; return; }
        Inv(a, (n + 1) >> 1, b);
        int len = FFT.Init(2 * n - 1);
        Fill(X, a, n, len), Fill(b, b, n, len);
        FFT.FFT(X, 0), FFT.FFT(b, 0);
        for (int i = 0; i < len; i++)   b[i] = mul(b[i], sub(2, mul(b[i], X[i])));
        FFT.FFT(b, 1), Fill(b, b, n, len);
    }
    void Log(T *a, int n, T *b) {
        Der(a, n, AL), Inv(a, n, BL), Mul(AL, n, BL, n, b);
        Int(b, n, b);   Fill(b, b, n, FFT.n);
    }
    void Exp(T *a, int n, T *b) {
        if (n == 1) { b[0] = 1; return; }
        Exp(a, (n + 1) >> 1, b);    Log(b, n, X);
        X[0] = sub(a[0] + 1, X[0]);
        for (int i = 1; i < n; i++) X[i] = sub(a[i], X[i]);
        int len = FFT.Init(2 * n - 1);
        Fill(X, X, n, len), Fill(b, b, n, len);
        FFT.FFT(X, 0), FFT.FFT(b, 0);
        Dot_Mul(X, b, len, b);
        FFT.FFT(b, 1), Fill(b, b, n, len);
    }
    void To_egf(T *a, int n, T *b) { Dot_Mul(a, fac, n, b); }
    void To_ogf(T *a, int n, T *b) { Dot_Mul(a, invfac, n, b); }
    void Bin_Mul(T *a, int n, T *b, int m, T *c) {
        To_ogf(a, n, AA), To_ogf(b, n, BB), Mul(AA, n, BB, m, c), To_egf(c, FFT.n, c);
    }
    void Bin_Log(T *a, int n, T *c) {
        To_ogf(a, n, AA), Log(AA, n, c), To_egf(c, n, c);
    }
    void Print(T *a, int n) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        } cout << '\n';
    }
};


long long Choose(int n, int m) { return n >= m && m >= 0 ? fac[n] * invfac[m] % P * invfac[n - m] % P : 0; }
long long sqr(long long x) { return x * x % P; }

Poly <int> poly;
int g[N << 2], f[N << 2], h[N << 2];

int main() {
    fac[0] = inv[0] = inv[1] = invfac[0] = 1;
    for (int i = 1; i < N; i++)    fac[i] = mul(fac[i - 1], i);
    for (int i = 2; i < N; i++)    inv[i] = mul(P - P / i, inv[P % i]);
    for (int i = 1; i < N; i++)    invfac[i] = mul(invfac[i - 1], inv[i]);

    int m;  scanf("%d", &m);
    g[0] = 1;
    for (int i = 1; i <= m; i++)    g[i] = qpow(i, i);
    poly.Bin_Log(g, m + 1, f);
    poly.Bin_Mul(f, m + 1, g, m + 1, h);
    for (int n = 1; n <= m; n++)    h[n] = mul(h[n], qpow(inv[n], n));
    for (int n = 1; n <= m; n++) {
        int ans = mul(n, qpow(sub(1, inv[n]), n));
        int ans1 = sub(n, h[n]), ans2 = add(ans1, ans);
        printf("0 %d %d\n", ans1, ans2);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}