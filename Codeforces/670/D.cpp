#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 10;

int n;
long long a[N], b[N], c[N], d[N];

long long t1, t2;

void work(int pos, long long x) {
    if (pos > n)    return;
    t1 += max(x, 0LL) - c[pos];
    c[pos] = max(x, 0LL);
    d[pos] = x;
    if (pos == 1) {
        t2 = min(x, 0LL);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)    scanf("%lld", a + i);
    for (int i = 1; i <= n; i++)    d[i] = a[i] - a[i - 1];

    for (int i = 1; i <= n; i++) {
        b[i] = min(d[i], 0LL);
        c[i] = max(d[i], 0LL);
    }
    // cout << "b:"; for (int i = 1; i <= n; i++)    cout << b[i] << ' ';    cout << '\n';
    // cout << "c:"; for (int i = 1; i <= n; i++)    cout << c[i] << ' ';    cout << '\n';
    // cout << "d:"; for (int i = 1; i <= n; i++)    cout << d[i] << ' ';    cout << '\n';

    t1 = 0, t2 = b[1];
    for (int i = 1; i <= n; i++)    t1 += c[i];
    // printf("t1 = %lld, t2 = %lld, ", t1, t2);
    printf("%lld\n", (t1 + t2 + 1) >> 1);
    
    int m;  scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int l, r, x;    scanf("%d %d %d", &l, &r, &x);
        work(l, d[l] + x);
        work(r + 1, d[r + 1] - x);
        // printf("t1 = %lld, t2 = %lld, ", t1, t2);
        printf("%lld\n", (t1 + t2 + 1) >> 1);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}