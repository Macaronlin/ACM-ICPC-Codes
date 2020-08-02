#include <bits/stdc++.h>

using namespace std;

const int P = 1000000000 + 7;
const int bas = 233;
const int invbas1 = 969827593;
int basn, basm, invbasn1, invbasm1;
const int N = 200000 + 10;

int mul(int a, int b) { return 1LL * a * b % P; }
int add(int a, int b) { return a + b >= P ? a + b - P : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + P : a - b; }

int qpow(int a, long long k = P - 2) {
    int res = 1;
    while (k) {
        if (k & 1)  res = mul(res, a);
        a = mul(a, a);
        k >>= 1;
    }
    return res;
}

char s[N], t[N];
int _pow[N];
int _pow1[N], _pow2[N];
int hs1[N], hs2[N];

int get_hash(int *hs, int l, int r) {
    return sub(hs[r], mul(hs[l - 1], _pow[r - l + 1]));
}

bool check(int pos1, int n, int pos2, int m, long long len) {
    int res1 = 0;
    if (pos1 + len - 1 <= 2 * n)    res1 = get_hash(hs1, pos1, pos1 + len - 1);
    else {
        long long len1 = len;
        res1 = get_hash(hs1, pos1, n);  len1 -= (n - pos1 + 1);
        if (len1 / n) {
            long long _ = _pow1[len1 / n];
            res1 = add(mul(res1, _), mul(hs1[n], mul(sub(_, 1), invbasn1)));
        }
        len1 -= len1 / n * n;
        if (len1) {
            res1 = add(mul(res1, _pow[len1]), hs1[len1]);
        }
    }
    int res2 = 0;
    if (pos2 + len - 1 <= 2 * m)    res2 = get_hash(hs2, pos2, pos2 + len - 1);
    else {
        long long len2 = len;
        res2 = get_hash(hs2, pos2, m);  len2 -= (m - pos2 + 1);
        if (len2 / m) {
            long long _ = _pow2[len2 / m];
            res2 = add(mul(res2, _), mul(hs2[m], mul(sub(_, 1), invbasm1)));
        }
        len2 -= len2 / m * m;
        if (len2) {
            res2 = add(mul(res2, _pow[len2]), hs2[len2]);
        }
    }
    int res = mul(9, mul(sub(qpow(bas, len), 1), invbas1));
    // cout << 9 << ' ' << sub(qpow(bas, len), 1) << ' ' << invbas1 << '\n';
    return add(res1, res2) == res;
}

int main() {
    freopen("aplusb.in", "r", stdin);
    freopen("aplusb.out", "w", stdout);
    _pow[0] = 1;
    for (int i = 1; i < N; i++) _pow[i] = mul(_pow[i - 1], bas);
    int T;  scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1); int n = strlen(s + 1);
        scanf("%s", t + 1); int m = strlen(t + 1);
        basn = qpow(bas, n);
        basm = qpow(bas, m);
        invbasn1 = qpow(sub(basn, 1));
        invbasm1 = qpow(sub(basm, 1));
        _pow1[0] = _pow2[0] = 1;
        for (int i = 1; i <= m; i++)    _pow1[i] = mul(_pow1[i - 1], basn);
        for (int i = 1; i <= n; i++)    _pow2[i] = mul(_pow2[i - 1], basm);
        for (int i = 1; i <= n; i++)    s[i] -= '0';
        for (int i = 1; i <= m; i++)    t[i] -= '0';
        for (int i = 1; i <= n; i++)    hs1[i] = add(mul(hs1[i - 1], bas), s[i]);
        for (int i = n + 1; i <= n * 2; i++)    hs1[i] = add(mul(hs1[i - 1], bas), s[i - n]);
        for (int i = 1; i <= m; i++)    hs2[i] = add(mul(hs2[i - 1], bas), t[i]);
        for (int i = m + 1; i <= m * 2; i++)    hs2[i] = add(mul(hs2[i - 1], bas), t[i - m]);
        // int H1 = m > 1 ? mul(hs1[n], mul(
        //     sub(qpow(qpow(bas, n), m - 1), 1), qpow(sub(qpow(bas, n), 1))
        // )) : 0;
        // int H2 = n > 1 ? mul(hs2[m], mul(
        //     sub(qpow(qpow(bas, m), n - 1), 1), qpow(sub(qpow(bas, m), 1))
        // )) : 0;
        int q;  scanf("%d", &q);
        while (q--) {
            long long pos;    scanf("%lld", &pos);
            int pos1 = (pos - 1) % n + 1, pos2 = (pos - 1) % m + 1;
            int ans = (s[pos1] + t[pos2]) % 10;
            long long L = 0, R = 1LL * n * m, _ans = 0;
            while (L <= R) {
                long long M = (L + R) >> 1;
                if (check(pos1 % n + 1, n, pos2 % m + 1, m, M)) {
                    L = M + 1;
                    _ans = M;
                }
                else    R = M - 1;
            }
            if (_ans == 1LL * n * m)    ans = (ans + 1) % 10;
            int _pos1 = (pos1 + _ans) % n + 1, _pos2 = (pos2 + _ans) % m + 1;
            if (s[_pos1] + t[_pos2] >= 10)  ans = (ans + 1) % 10;
            printf("%d", ans);
            // cout << _ans << ' ' << ans << '\n';
        } puts("");
    }
    return 0;
}